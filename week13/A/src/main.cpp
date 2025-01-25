#include <iostream>
#include <map>
#include <chrono>
#include "../include/prime_calculator.hpp"
#include <spdlog/spdlog.h>

int main(int argc, char* argv[]) {
    // Загружаем конфигурацию из файла
    std::map<std::string, int> config = loadConfig("src/config.cfg");

    // Проверяем, загружены ли все параметры
    if (config.find("start") == config.end() || config.find("end") == config.end() || config.find("numThreads") == config.end()) {
        spdlog::error("Отсутствуют параметры в конфигурационном файле.");
        return 1;
    }

    int start = config["start"];
    int end = config["end"];
    int numThreads = config["numThreads"];

    // Логируем параметры начала вычислений
    spdlog::info("Запуск вычислений простых чисел...");
    spdlog::info("Начало: {}, Конец: {}, Количество потоков: {}", start, end, numThreads);

    // Вычисления методом Work Stealing
    spdlog::info("Запуск метода Work Stealing...");
    auto start_time = std::chrono::high_resolution_clock::now();
    runWorkStealing(start, end, numThreads);
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;
    spdlog::info("Метод Work Stealing занял {} секунд.", duration.count());

    // Вычисления методом Shuffle
    spdlog::info("Запуск метода Shuffle...");
    start_time = std::chrono::high_resolution_clock::now();
    runShuffle(start, end, numThreads);
    end_time = std::chrono::high_resolution_clock::now();
    duration = end_time - start_time;
    spdlog::info("Метод Shuffle занял {} секунд.", duration.count());

    return 0;
}
