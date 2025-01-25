#include <iostream>
#include <map>
#include <chrono>
#include "../include/prime_finder.hpp"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

int main() {
     auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    spdlog::logger logger("my_logger", console_sink);
    logger.set_level(spdlog::level::debug);

    // Загружаем конфигурацию из файла
    std::map<std::string, int> config = loadConfig("config.cfg");

    // Проверяем, загружены ли все параметры
    if (config.empty()) {
        spdlog::error("Не удалось загрузить конфигурацию или отсутствуют необходимые параметры.");
        return 1;
    }

    int start = config["start"];
    int end = config["end"];
    int numThreads = config["numThreads"];

     if (start >= end) {
         spdlog::error("Начальное значение должно быть меньше конечного.");
        return 1;
    }
     if (numThreads <= 0) {
         spdlog::error("Количество потоков должно быть больше 0.");
        return 1;
    }
    
    // Логируем параметры начала вычислений
    spdlog::info("Запуск вычислений простых чисел...");
    spdlog::info("Начало: {}, Конец: {}, Количество потоков: {}", start, end, numThreads);

    // Вычисления методом Work Stealing
    spdlog::info("Запуск метода Work Stealing...");
    runWorkStealing(start, end, numThreads);

    // Вычисления методом Shuffle
    spdlog::info("Запуск метода Shuffle...");
    runShuffle(start, end, numThreads);
    return 0;
}
