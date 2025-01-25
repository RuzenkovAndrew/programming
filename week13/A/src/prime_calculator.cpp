#include "../include/prime_calculator.hpp"
#include <iostream>
#include <cmath>
#include <future>
#include <random>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <chrono>
#include <spdlog/spdlog.h>
#include <mutex>
#include <string>

std::mutex results_mutex;

// Функция для проверки числа на простоту
bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i <= std::sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

// Функция для поиска простых чисел с использованием метода Work Stealing
void workStealing(int start, int end, std::vector<int>& results) {
    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) {
            std::lock_guard<std::mutex> lock(results_mutex); // Синхронизация доступа к результатам
            results.push_back(i);
        }
    }
}

// Функция для поиска простых чисел с использованием метода Shuffle
void shuffleWork(int start, int end, std::vector<int>& results) {
    std::vector<int> range(end - start + 1);
    std::iota(range.begin(), range.end(), start); // Заполняем диапазон чисел
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(range.begin(), range.end(), g); // Перемешиваем числа

    for (int i = 0; i < range.size(); ++i) {
        if (isPrime(range[i])) {
            std::lock_guard<std::mutex> lock(results_mutex); // Синхронизация доступа к результатам
            results.push_back(range[i]);
        }
    }
}

// Функция для выполнения вычислений методом Work Stealing
void runWorkStealing(int start, int end, int numThreads) {
    std::vector<std::future<void>> futures;
    std::vector<int> results;
    int range = (end - start + 1) / numThreads; // Разделяем диапазон на части для каждого потока

    // Запускаем потоки
    for (int i = 0; i < numThreads; ++i) {
        int threadStart = start + i * range;
        int threadEnd = (i == numThreads - 1) ? end : threadStart + range - 1;
        futures.push_back(std::async(std::launch::async, workStealing, threadStart, threadEnd, std::ref(results)));
    }

    // Ожидаем завершения всех потоков
    for (auto& future : futures) {
        future.get();
    }

    // Собираем все простые числа в строку
    std::string result_str = "Простые числа: ";
    for (const auto& prime : results) {
        result_str += std::to_string(prime) + " ";
    }

    // Выводим все простые числа в одном логе
    // spdlog::info(result_str);
    spdlog::info("Найдено {} простых чисел методом Work Stealing.", results.size());
}

// Функция для выполнения вычислений методом Shuffle
void runShuffle(int start, int end, int numThreads) {
    std::vector<int> results;
    int range = (end - start + 1) / numThreads;
    std::vector<std::future<void>> futures;

    // Запускаем потоки
    for (int i = 0; i < numThreads; ++i) {
        int threadStart = start + i * range;
        int threadEnd = (i == numThreads - 1) ? end : threadStart + range - 1;
        futures.push_back(std::async(std::launch::async, shuffleWork, threadStart, threadEnd, std::ref(results)));
    }

    // Ожидаем завершения всех потоков
    for (auto& future : futures) {
        future.get();
    }

    // Собираем все простые числа в строку
    std::string result_str = "Простые числа: ";
    for (const auto& prime : results) {
        result_str += std::to_string(prime) + " ";
    }

    // Выводим все простые числа в одном логе
    // spdlog::info(result_str);
    spdlog::info("Найдено {} простых чисел методом Shuffle.", results.size());
}

// Функция для загрузки конфигурации из файла
std::map<std::string, int> loadConfig(const std::string& filename) {
    std::map<std::string, int> config;
    std::ifstream configFile(filename);
    
    // Проверка открытия файла
    if (!configFile.is_open()) {
        spdlog::error("Не удалось открыть конфигурационный файл: {}", filename);
        return config;
    }

    std::string line;
    while (std::getline(configFile, line)) {
        std::istringstream stream(line);
        std::string key;
        int value;
        if (std::getline(stream, key, '=') && stream >> value) {
            config[key] = value;
        }
    }

    configFile.close();
    return config;
}
