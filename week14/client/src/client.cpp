#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    int client_socket;
    const char* SERVER_IP = "127.0.0.1";
    const int PORT = 8080;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        std::cerr << "Не удалось создать сокет!" << std::endl;
        return -1;
    }

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        std::cerr << "Не удалось подключиться к серверу!" << std::endl;
        close(client_socket);
        return -1;
    }

    std::string user_name;
    std::cout << "Введите ваше имя: ";
    std::getline(std::cin, user_name);
    send(client_socket, user_name.c_str(), user_name.length(), 0);

    // Поток для получения сообщений
    std::thread receive_messages([client_socket]() {
        char buffer[1024];
        while (true) {
            int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
            if (bytes_received <= 0) {
                std::cerr << "Сервер отключен!" << std::endl;
                break;
            }

            buffer[bytes_received] = '\0';
            std::cout << buffer << std::endl;
        }
    });

    std::string message;
    while (true) {
        std::getline(std::cin, message);
        send(client_socket, message.c_str(), message.length(), 0);
    }

    close(client_socket);
    receive_messages.join();
    return 0;
}
