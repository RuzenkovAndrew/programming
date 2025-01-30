#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <nlohmann/json.hpp>
#include "../include/spdlog/spdlog.h"
#include "../include/spdlog/sinks/basic_file_sink.h"
#include "../include/spdlog/sinks/stdout_color_sinks.h"

using json = nlohmann::json;

#define DELAY 1
#define PORT 12345
#define SERVER_IP "127.0.0.1"

int delay = DELAY;
int location = 1;
int haveFlowers = 0;
int haveSword = 0;
int ateSpinach = 0;
int dead = 0;
int killedSlug = 0;
int killedDragon = 0;
int savedPrincess = 0;
int coward = 0;
std::string playerName = "";

// Инициализация логгера
std::shared_ptr<spdlog::logger> logger;

void setupLogger() {
    try {
        auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs.txt", true);
        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        std::vector<spdlog::sink_ptr> sinks { file_sink, console_sink };
        logger = std::make_shared<spdlog::logger>("multi_sink", sinks.begin(), sinks.end());
        
        spdlog::set_default_logger(logger);
        spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] %v");
        spdlog::info("Logger is initialized");
    }
    catch (const spdlog::spdlog_ex &ex) {
        std::cerr << "Log initialization failed: " << ex.what() << std::endl;
    }
}

void doError() {
    spdlog::error("Что!??");
    sleep(delay);
}

int getAction() {
    int action;
    std::cin >> action;
    return action;
}

void doMove() {
    spdlog::debug("Moving...");
    std::cout << ".";
    std::cout.flush();
    sleep(delay);
    std::cout << ".";
    std::cout.flush();
    sleep(delay);
    std::cout << ".";
    std::cout.flush();
    sleep(delay);
    std::cout << "\n\n\n";
}

void showMainMenu() {
    std::cout << "\nГлавное меню:\n";
    std::cout << "1. Продолжить игру\n";
    std::cout << "2. Начать новую игру\n";
    std::cout << "3. Сохранить игру\n"; // Добавлено сохранение
    std::cout << "4. Выйти\n";
    std::cout << "Выберите действие: ";
}

int sendData(const std::string& message, int socket) {
    int bytes_sent = send(socket, message.c_str(), message.length(), 0);
    if (bytes_sent == -1) {
        spdlog::error("Ошибка при отправке данных серверу");
        close(socket);
        return 1;
    }
    return 0;
}

std::string receiveData(int socket) {
    char buffer[1024];
    int bytes_received = recv(socket, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        spdlog::error("Ошибка при получении данных от сервера.");
        close(socket);
        return "";
    }
    if (bytes_received == 0) {
        spdlog::warn("Сервер отключился.");
        close(socket);
        return "";
    }
    return std::string(buffer, bytes_received);
}

int saveGame(int socket) {
    json data;
    data["action"] = "save";
    data["playerName"] = playerName; // Добавлено имя игрока
    data["data"]["delay"] = delay;
    data["data"]["location"] = location;
    data["data"]["haveFlowers"] = haveFlowers;
    data["data"]["haveSword"] = haveSword;
    data["data"]["ateSpinach"] = ateSpinach;
    data["data"]["dead"] = dead;
    data["data"]["killedSlug"] = killedSlug;
    data["data"]["killedDragon"] = killedDragon;
    data["data"]["savedPrincess"] = savedPrincess;
    data["data"]["coward"] = coward;

    std::string message = data.dump();
    if (sendData(message, socket) != 0) {
        return 1;
    }

    std::string response = receiveData(socket);
    if (response.empty()) {
        return 1;
    }
    try {
        json resp = json::parse(response);
        if (resp.contains("message") && resp["message"] == "Game saved") {
            spdlog::info("Игра сохранена на сервере для игрока {}.", playerName);
            return 0;
        } else {
            spdlog::error("Ошибка при сохранении игры на сервере для игрока {}.", playerName);
            return 1;
        }
    } catch (const json::parse_error &e) {
        spdlog::error("Ошибка разбора JSON: {}", e.what());
        return 1;
    }
}

int loadGame(int socket, const std::string& name) {
    json request;
    request["action"] = "load";
    request["playerName"] = name; // Добавлено имя игрока
    std::string message = request.dump();
    if (sendData(message, socket) != 0) {
        return 1;
    }
    std::string response = receiveData(socket);
    if (response.empty()) {
        return 1;
    }
    try {
        json data = json::parse(response);
        if (data.contains("message") && data["message"] == "Game not found") {
            spdlog::info("Нет сохраненной игры для игрока {}.", name);
            return 1;
        } else {
            if (data.contains("playerName")) playerName = data["playerName"];
            if (data.contains("delay")) delay = data["delay"].get<int>();
            if (data.contains("location")) location = data["location"].get<int>();
            if (data.contains("haveFlowers")) haveFlowers = data["haveFlowers"].get<int>();
            if (data.contains("haveSword")) haveSword = data["haveSword"].get<int>();
            if (data.contains("ateSpinach")) ateSpinach = data["ateSpinach"].get<int>();
            if (data.contains("dead")) dead = data["dead"].get<int>();
            if (data.contains("killedSlug")) killedSlug = data["killedSlug"].get<int>();
            if (data.contains("killedDragon")) killedDragon = data["killedDragon"].get<int>();
            if (data.contains("savedPrincess")) savedPrincess = data["savedPrincess"].get<int>();
            if (data.contains("coward")) coward = data["coward"].get<int>();
            spdlog::info("Игра загружена с сервера для игрока {}.", playerName);
            return 0;
        }
    } catch (const json::parse_error& e) {
        spdlog::error("Ошибка разбора JSON: {}", e.what());
        return 1;
    }
}

// Локации и действия
void doLocation1() {
    std::cout << "Вы видите вход в пещеру на севере.\n";
    std::cout << "Вы слышите, как принцесса кричит: \"Помогите!\"\n";
    std::cout << "Вы также слышите громкий рев.\n";
    std::cout << "Что вы делаете?\n";
    std::cout << "1) Войти в пещеру\n";
    std::cout << "2) Убежать\n";
    std::cout << "? ";
    int action = getAction();
    switch (action) {
        case 1:
            location = 2;
            doMove();
            break;
        case 2:
            spdlog::warn("Вы убежали как трус.");
            coward = 1;
            dead = 1;
            break;
        default:
            doError();
            break;
    }
}

void doLocation2() {
    std::cout << "Вы видите слизня.\n";
    std::cout << "Что вы делаете?\n";
    std::cout << "1) Убить слизня\n";
    std::cout << "2) Убежать\n";
    std::cout << "3) Применить цветок\n"; // Исправлено
    std::cout << "4) Пройти мимо слизня\n"; // Новый вариант
    std::cout << "? ";
    int action = getAction();
    switch (action) {
        case 1:
            if (haveSword == 1) {
                killedSlug = 1;
                spdlog::info("Вы убили слизня.");
                location = 3; // Переход к следующей локации
            } else {
                spdlog::warn("У вас нет меча, чтобы убить слизня.");
                doError();
            }
            break;
        case 2:
            spdlog::warn("Вы убежали от слизня.");
            coward = 1;
            dead = 1;
            break;
        case 3:
            if (haveFlowers == 1) {
                spdlog::info("Слизень испугался и сбежал.");
                killedSlug = 1;
                location = 3; // Переход к следующей локации
            } else {
                spdlog::warn("У вас нет цветов, чтобы использовать.");
                doError();
            }
            break;
        case 4:
            spdlog::info("Вы прошли мимо слизня.");
            location = 3; // Переход к следующей локации
            break;
        default:
            doError();
            break;
    }
}

void doLocation3() {
    std::cout << "Вы видите Дракона.\n";
    std::cout << "Принцесса просит вас её спасти.\n";
    std::cout << "Что вы делаете?\n";
    std::cout << "1) Убить Дракона\n";
    std::cout << "2) Сдаться Дракону\n";
    std::cout << "3) Дать ему шпинат\n";
    std::cout << "? ";
    int action = getAction();
    switch (action) {
        case 1:
            if (haveSword == 1) {
                spdlog::info("Вы убили Дракона и спасли принцессу.");
                savedPrincess = 1;
                killedDragon = 1;
            } else {
                spdlog::warn("Вы не смогли убить Дракона.");
                dead = 1;
            }
            break;
        case 2:
            spdlog::warn("Дракон убил вас.");
            dead = 1;
            break;
        case 3:
            if (ateSpinach == 1) {
                spdlog::info("Дракон уснул.");
            } else {
                spdlog::warn("Дракон разозлился и убил вас.");
                dead = 1;
            }
            break;
        default:
            doError();
            break;
    }
}

void doLocation4() {
    std::cout << "Вы видите меч, хотите его взять?\n";
    std::cout << "1) Да\n";
    std::cout << "2) Нет\n";
    std::cout << "? ";
    int action = getAction();
    switch (action) {
        case 1:
            haveSword = 1;
            spdlog::info("Вы взяли меч.");
            break;
        case 2:
            spdlog::info("Вы решили не брать меч.");
            break;
        default:
            doError();
            break;
    }
    location = 1;
}

void doLocation5() {
    std::cout << "Вы видите цветы. Хотите их взять?\n";
    std::cout << "1) Да\n";
    std::cout << "2) Нет\n";
    std::cout << "? ";
    int action = getAction();
    switch (action) {
        case 1:
            haveFlowers = 1;
            spdlog::info("Вы взяли цветы.");
            break;
        case 2:
            spdlog::info("Вы решили не брать цветы.");
            break;
        default:
            doError();
            break;
    }
    location = 1;
}

void doLocation6() {
    std::cout << "Вы видите шпинат, хотите его съесть?\n";
    std::cout << "1) Да\n";
    std::cout << "2) Нет\n";
    std::cout << "? ";
    int action = getAction();
    switch (action) {
        case 1:
            spdlog::info("Вы съели шпинат.");
            ateSpinach = 1;
            break;
        case 2:
            spdlog::info("Вы решили не есть шпинат.");
            break;
        default:
            doError();
            break;
    }
    location = 1;
}

// Новая локация 7
void doLocation7() {
    std::cout << "Вы попали в лес. Здесь много опасных созданий.\n";
    std::cout << "Что вы делаете?\n";
    std::cout << "1) Исследовать лес\n";
    std::cout << "2) Вернуться назад\n";
    std::cout << "? ";
    int action = getAction();
    switch (action) {
        case 1:
            spdlog::info("Вы исследуете лес и находите редкий артефакт!");
            // Здесь можно добавить логику для артефакта
            break;
        case 2:
            location = 1; // Вернуться в предыдущую локацию
            break;
        default:
            doError();
            break;
    }
}

void playGame() {
    setupLogger();
    int client_socket;
    struct sockaddr_in server_addr;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        spdlog::error("Не удалось создать сокет.");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        spdlog::error("Неправильный адрес");
        close(client_socket);
        return;
    }

    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        spdlog::error("Не удалось подключиться к серверу.");
        close(client_socket);
        return;
    }
    spdlog::info("Подключено к серверу {}:{}", SERVER_IP, PORT);
    int choice = 0;
    while (choice != 4) {
        showMainMenu();
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1: {
                std::string name;
                std::cout << "Введите имя персонажа: ";
                std::getline(std::cin, name);
                if (loadGame(client_socket, name) != 0) {
                    continue;
                }
                break;
            }
            case 2: {
                std::cout << "Введите имя персонажа: ";
                std::getline(std::cin, playerName);
                break;
            }
            case 3: // Сохранение игры
                if (saveGame(client_socket) != 0) {
                    std::cout << "Ошибка при сохранении игры.\n";
                }
                break;
            case 4:
                // Сохранение перед выходом
                saveGame(client_socket);
                std::cout << "Выход.\n";
                spdlog::info("Выход.");
                break;
            default:
                std::cout << "Неверный ввод. Попробуйте снова.\n";
                break;
        }
        if (choice == 1 || choice == 2) {
            break;
        }
    }
    if (choice == 4) return;
    while (dead == 0) {
        switch (location) {
            case 1:
                doLocation1();
                break;
            case 2:
                doLocation2();
                break;
            case 3:
                doLocation3();
                break;
            case 4:
                doLocation4();
                break;
            case 5:
                doLocation5();
                break;
            case 6:
                doLocation6();
                break;
            case 7:
                doLocation7(); // Новая локация
                break;
            default:
                doError();
                break;
        }

        if (dead == 1) {
            break;
        }
    }
    saveGame(client_socket);
    close(client_socket);
    if (coward == 1) {
        spdlog::warn("Вы - трус.");
        std::cout << "Вы - трус.\n";
    } else if (savedPrincess == 1) {
        spdlog::info("Вы - герой!");
        std::cout << "Вы - герой!\n";
    }
    std::cout << "Game Over!\n";
}

int main() {
    playGame();
    return 0;
}

