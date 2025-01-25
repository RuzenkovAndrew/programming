#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <stdexcept>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include "../include/server.hpp"

int main() {
    int server_socket, client_socket;
    sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    const int PORT = 8080;

    try {
        create_socket(server_socket);

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(PORT);
        server_addr.sin_addr.s_addr = INADDR_ANY;

        bind_socket(server_socket, server_addr);
        listen_socket(server_socket);

        std::cout << "Сервер запущен, ожидаем подключений..." << std::endl;

        std::vector<int> clients;
        std::mutex clients_mutex;

        // Главный цикл сервера для принятия подключений от клиентов
        while (true) {
            client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
            if (client_socket == -1) {
                throw std::runtime_error("Ошибка при принятии подключения!");
            }

            {
                std::lock_guard<std::mutex> guard(clients_mutex);
                clients.push_back(client_socket);
            }

            // Выводим сообщение о подключении нового клиента
            std::cout << "Новый пользователь подключен!" << std::endl;

            std::thread(handle_client, client_socket, std::ref(clients), std::ref(clients_mutex)).detach();
        }

        close(server_socket);
    } catch (const std::runtime_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        if (server_socket != -1) {
            close(server_socket);
        }
        return -1;
    }

    return 0;
}
