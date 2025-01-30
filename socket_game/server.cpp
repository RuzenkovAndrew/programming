#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <thread>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <csignal>
#include <nlohmann/json.hpp>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sqlite3.h>
#include <fstream>
#include <mutex>
#include "../include/spdlog/spdlog.h"
#include "../include/spdlog/sinks/basic_file_sink.h"

using json = nlohmann::json;

const int PORT = 12345;
std::vector<std::thread> client_threads;
sqlite3* db;
std::mutex db_mutex;
std::shared_ptr<spdlog::logger> logger;

void setupLogger() {
    try {
        logger = spdlog::create<spdlog::sinks::basic_file_sink_mt>("server_logger", "server_logs.txt", true);
        logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v");
        spdlog::info("Логгер успешно инициализирован.");
    } catch (const spdlog::spdlog_ex& ex) {
        std::cerr << "Ошибка инициализации лога: " << ex.what() << std::endl;
    }
}

void initDB() {
    int rc = sqlite3_open("game_server.db", &db);
    if (rc) {
        spdlog::error("Не удалось открыть базу данных: {}", sqlite3_errmsg(db));
    } else {
        spdlog::info("База данных успешно открыта");
        std::string sql = "CREATE TABLE IF NOT EXISTS game_data ("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                          "player_name TEXT UNIQUE NOT NULL,"
                          "data TEXT NOT NULL);";

        char* errMsg = 0;
        rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);
        if (rc != SQLITE_OK) {
            spdlog::error("Ошибка SQL: {}", errMsg);
            sqlite3_free(errMsg);
        } else {
            spdlog::info("Таблица успешно создана");
        }
    }
}

void handleClient(int client_socket) {
    char buffer[1024];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        std::string received_data(buffer, bytes_received);
        spdlog::info("Получены данные от клиента: {}", received_data);
    
        try {
            json j = json::parse(received_data);
            if (j.contains("action")) {
                std::string action = j["action"];
                if (action == "load") {
                    if (!j.contains("playerName") || !j["playerName"].is_string()) {
                        spdlog::error("Неверное или отсутствующее имя игрока в действии загрузки");
                        json response;
                        response["message"] = "Неверное имя игрока";
                        send(client_socket, response.dump().c_str(), response.dump().size(), 0);
                        continue;
                    }

                    std::string player_name = j["playerName"];
                    std::string game_data;

                    {
                        std::lock_guard<std::mutex> lock(db_mutex);
                        std::string sql = "SELECT data FROM game_data WHERE player_name = ?";
                        sqlite3_stmt* stmt;
                        int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
                        if (rc != SQLITE_OK) {
                            spdlog::error("Ошибка подготовки запроса: {}", sqlite3_errmsg(db));
                        }

                        sqlite3_bind_text(stmt, 1, player_name.c_str(), -1, SQLITE_STATIC);

                        if (sqlite3_step(stmt) == SQLITE_ROW) {
                            game_data = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
                            spdlog::info("Загружены данные игры для игрока: {}", player_name);
                        }
                        sqlite3_finalize(stmt);
                    }

                    json response;
                    if (game_data.empty()) {
                        response["message"] = "Игра не найдена";
                    } else {
                        response["message"] = "Игра загружена";
                        response["playerName"] = player_name;
                        response["data"] = game_data;
                    }

                    std::string response_str = response.dump();
                    send(client_socket, response_str.c_str(), response_str.size(), 0);
                    spdlog::info("Отправлены данные игры клиенту: {}", response_str);
                } else if (action == "save") {
                    if (!j.contains("playerName") || !j["playerName"].is_string() || 
                        !j.contains("data") || !j["data"].is_object()) {
                        spdlog::error("Неверное или отсутствующее имя игрока или данные в действии сохранения");
                        json response;
                        response["message"] = "Неверное имя игрока или данные";
                        send(client_socket, response.dump().c_str(), response.dump().size(), 0);
                        continue;
                    }

                    std::string player_name = j["playerName"];
                    std::string data = j["data"].dump(); // Сериализуем данные в строку

                    {
                        std::lock_guard<std::mutex> lock(db_mutex);
                        std::string sql = "INSERT OR REPLACE INTO game_data (player_name, data) VALUES (?, ?)";
                        sqlite3_stmt* stmt;
                        int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
                        if (rc != SQLITE_OK) {
                            spdlog::error("Ошибка подготовки запроса: {}", sqlite3_errmsg(db));
                        }
                        sqlite3_bind_text(stmt, 1, player_name.c_str(), -1, SQLITE_STATIC);
                        sqlite3_bind_text(stmt, 2, data.c_str(), -1, SQLITE_STATIC);

                        rc = sqlite3_step(stmt);
                        if (rc != SQLITE_DONE) {
                            spdlog::error("Ошибка при вставке данных игры {}", sqlite3_errmsg(db));
                        } else {
                            spdlog::info("Данные игры сохранены для игрока: {}", player_name);
                        }
                        sqlite3_finalize(stmt);
                    }

                    json response;
                    response["message"] = "Игра сохранена";
                    std::string response_str = response.dump();
                    send(client_socket, response_str.c_str(), response_str.size(), 0);
                    spdlog::info("Отправлено 'сохранено' клиенту: {}", response_str);
                } else if (action == "savePath") {
                    // Обработка сохранения при выборе пути
                    if (!j.contains("playerName") || !j["playerName"].is_string() || 
                        !j.contains("data") || !j["data"].is_object()) {
                        spdlog::error("Неверное или отсутствующее имя игрока или данные в действии сохранения пути");
                        json response;
                        response["message"] = "Неверное имя игрока или данные";
                        send(client_socket, response.dump().c_str(), response.dump().size(), 0);
                        continue;
                    }

                    std::string player_name = j["playerName"];
                    std::string data = j["data"].dump(); // Сериализуем данные в строку

                    {
                        std::lock_guard<std::mutex> lock(db_mutex);
                        std::string sql = "INSERT OR REPLACE INTO game_data (player_name, data) VALUES (?, ?)";
                        sqlite3_stmt* stmt;
                        int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
                        if (rc != SQLITE_OK) {
                            spdlog::error("Ошибка подготовки запроса: {}", sqlite3_errmsg(db));
                        }
                        sqlite3_bind_text(stmt, 1, player_name.c_str(), -1, SQLITE_STATIC);
                        sqlite3_bind_text(stmt, 2, data.c_str(), -1, SQLITE_STATIC);

                        rc = sqlite3_step(stmt);
                        if (rc != SQLITE_DONE) {
                            spdlog::error("Ошибка при вставке данных игры {}", sqlite3_errmsg(db));
                        } else {
                            spdlog::info("Данные игры сохранены для игрока: {}", player_name);
                        }
                        sqlite3_finalize(stmt);
                    }

                    json response;
                    response["message"] = "Игра сохранена при выборе пути";
                    std::string response_str = response.dump();
                    send(client_socket, response_str.c_str(), response_str.size(), 0);
                    spdlog::info("Отправлено 'сохранено при выборе пути' клиенту: {}", response_str);
                } else {
                    json response;
                    response["message"] = "Неизвестное действие";
                    std::string response_str = response.dump();
                    send(client_socket, response_str.c_str(), response_str.size(), 0);
                    spdlog::error("Получено неизвестное действие от клиента");
                }
            } else {
                json response;
                response["message"] = "Неверный формат JSON";
                std::string response_str = response.dump();
                send(client_socket, response_str.c_str(), response_str.size(), 0);
                spdlog::error("Получен неверный формат JSON от клиента");
            }
        } catch (const json::parse_error& e) {
            spdlog::error("Ошибка разбора JSON: {}", e.what());
            json response;
            response["message"] = "Ошибка разбора JSON";
            std::string response_str = response.dump();
            send(client_socket, response_str.c_str(), response_str.size(), 0);
        }
        memset(buffer, 0, sizeof(buffer));
    }

    if (bytes_received == 0) {
        spdlog::info("Клиент отключился");
    } else if (bytes_received < 0) {
        spdlog::error("Ошибка при получении данных");
    }

    close(client_socket);
}

int main() {
    setupLogger();
    initDB();

    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        spdlog::error("Ошибка создания сокета");
        return 1;
    }
    spdlog::info("Сокет успешно создан");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        spdlog::error("Ошибка привязки сокета");
        return 1;
    }
    spdlog::info("Сокет успешно привязан");

    if (listen(server_socket, 5) < 0) {
        spdlog::error("Ошибка прослушивания на сокете");
        return 1;
    }
    spdlog::info("Сервер слушает на порту {}", PORT);
    
    while (true) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            spdlog::error("Ошибка принятия соединения");
            continue;
        }

        spdlog::info("Соединение принято от {}", inet_ntoa(client_addr.sin_addr));

        std::thread client_thread(handleClient, client_socket);
        client_threads.push_back(std::move(client_thread));
    }

    close(server_socket);
    sqlite3_close(db);

    return 0;
}

