#include <vector>
#include <mutex>
#include <string>
#include <netinet/in.h>

extern std::vector<std::string> message_history;
extern std::mutex history_mutex;

void create_socket(int& socket_fd);
void bind_socket(int socket_fd, sockaddr_in& server_addr);
void listen_socket(int socket_fd);
void broadcast_message(const std::vector<int>& clients, std::mutex& clients_mutex, const std::string& message, int sender_socket);
void send_message_history(int client_socket);
void handle_client(int client_socket, std::vector<int>& clients, std::mutex& clients_mutex);

