#include "../include/server.hpp"
#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Инициализация глобальных переменных
std::vector<std::string> message_history;
std::mutex history_mutex;

// Функция для работы с сокетами
void create_socket(int& socket_fd) {
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        throw std::runtime_error("Не удалось создать сокет!");
    }
}

// Функция для привязки сокета
void bind_socket(int socket_fd, sockaddr_in& server_addr) {
    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        throw std::runtime_error("Не удалось привязать сокет!");
    }
}

// Функция для начала прослушивания сокета
void listen_socket(int socket_fd) {
    if (listen(socket_fd, 0) == -1) {
        throw std::runtime_error("Не удалось начать прослушивание!");
    }
}

// Функция для рассылки сообщений всем подключённым клиентам, кроме отправителя
void broadcast_message(const std::vector<int>& clients, std::mutex& clients_mutex, const std::string& message, int sender_socket) {
    std::lock_guard<std::mutex> guard(clients_mutex);
    for (int client_socket : clients) {
        if (client_socket != sender_socket) {
            send(client_socket, message.c_str(), message.length(), 0);
        }
    }
}

// Функция для отправки истории сообщений новому клиенту
void send_message_history(int client_socket) {
    std::lock_guard<std::mutex> guard(history_mutex);
    for (const auto& msg : message_history) {
        std::string message_with_newline = msg + "\n";  // Добавляем новую строку после каждого сообщения
        send(client_socket, message_with_newline.c_str(), message_with_newline.length(), 0);
    }
}

// Функция для обработки клиента
void handle_client(int client_socket, std::vector<int>& clients, std::mutex& clients_mutex) {
    char buffer[1024];
    std::string client_name;
    bool name_set = false;

    try {
        // Отправляем историю сообщений новому клиенту
        send_message_history(client_socket);

        while (!name_set) {
            int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
            if (bytes_received <= 0) {
                break;
            }

            buffer[bytes_received] = '\0';
            client_name = std::string(buffer);
            if (client_name.empty()) continue;

            name_set = true;
            std::string welcome_message = "\nПривет, " + client_name + ", теперь вы можете начинать общение.";
            send(client_socket, welcome_message.c_str(), welcome_message.length(), 0);
        }

        std::string message;
        while (true) {
            int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
            if (bytes_received <= 0) {
                break;
            }

            buffer[bytes_received] = '\0';
            message = std::string(buffer);

            std::string formatted_message = "[" + client_name + "] - " + message;

            {
                std::lock_guard<std::mutex> guard(history_mutex);
                if (message_history.size() >= 100000) {
                    message_history.erase(message_history.begin());
                }
                message_history.push_back(formatted_message);
            }

            broadcast_message(clients, clients_mutex, formatted_message, client_socket);
        }

        close(client_socket);
    } catch (const std::runtime_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        close(client_socket);
    }
}
