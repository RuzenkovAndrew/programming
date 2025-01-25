#include "../include/prime_finder.hpp"
#include <iostream>
#include <vector>
#include <thread>
#include <deque>
#include <random>
#include <chrono>
#include <numeric>
#include <algorithm>
#include <atomic>
#include <mutex>
#include <fstream>
#include <sstream>
#include <spdlog/spdlog.h>

using namespace std;

// Проверка на простоту
bool isPrime(int n) {
    if (n <= 1)
        return false;

    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

void workStealingPrimeSearch(int start, int end, int numThreads, vector<int>& results, mutex& mtx) {
    vector<deque<int>> localQueues(numThreads);
    vector<thread> threads(numThreads);
    atomic<bool> done(false);
    vector<mutex> mutexes(numThreads); // Move declaration here
    
    // Инициализация локальных очередей
    for (int i = start; i <= end; ++i) {
      localQueues[i % numThreads].push_back(i);
    }

    // Функция для каждого потока
    auto threadFunction = [&](int threadId) {
      while (!done) {
          int number = 0;
          
          // Попытка получить задачу из локальной очереди
          {
            lock_guard<mutex> lock(mutexes[threadId]);
            if (!localQueues[threadId].empty()) {
              number = localQueues[threadId].back();
              localQueues[threadId].pop_back();
            }
            else {
               //Попытка украсть
                int target = 0;
                bool stolen = false;
                for (int i = 0; i < numThreads; i++) {
                   target = (threadId + i) % numThreads;
                  if(target == threadId) continue;
                    {
                        lock_guard<mutex> lock_target(mutexes[target]);
                         if (!localQueues[target].empty()) {
                            number = localQueues[target].front();
                            localQueues[target].pop_front();
                            stolen = true;
                            break;
                        }
                   }
                }
                 if(!stolen){
                     this_thread::yield();
                    continue;
                 }
              }
          }
          if(number !=0){
            if (isPrime(number)) {
                lock_guard<mutex> lock(mtx);
                results.push_back(number);
              }
           }
          bool all_empty = true;
          for(int i=0; i< numThreads; i++){
               lock_guard<mutex> lock(mutexes[i]);
              if(!localQueues[i].empty())
                all_empty = false;
          }
          if(all_empty){
              done = true;
          }
          
      }
    };

    // Запуск потоков
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = thread(threadFunction, i);
    }

    // Ожидание завершения потоков
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }
}

void runWorkStealing(int start, int end, int numThreads) {
     vector<int> results;
     mutex mtx;
    auto start_time = chrono::high_resolution_clock::now();
    workStealingPrimeSearch(start, end, numThreads, results, mtx);
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end_time - start_time;

    spdlog::info("Work Stealing: Found {} prime numbers in {} seconds", results.size(), duration.count());
    for (int prime : results) {
        spdlog::debug("Found prime: {}", prime);
    }
}

void uniformPrimeSearch(int start, int end, vector<int>& numbers, vector<int>& results, mutex& mtx) {
    int numThreads = thread::hardware_concurrency();
    vector<thread> threads;
    int range = numbers.size() / numThreads;
    
    for (int i = 0; i < numThreads; ++i) {
        int threadStart = i * range;
        int threadEnd = (i == numThreads - 1) ? numbers.size() : threadStart + range;
        threads.emplace_back([&, threadStart, threadEnd](){
            for (int j= threadStart; j < threadEnd; ++j){
                if (isPrime(numbers[j])){
                   lock_guard<mutex> lock(mtx);
                    results.push_back(numbers[j]);
                }
            }
         });
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

void runShuffle(int start, int end, int numThreads) {
    vector<int> numbers(end - start + 1);
    iota(numbers.begin(), numbers.end(), start);

    // Перемешивание чисел
    random_device rd;
    mt19937 g(rd());
    shuffle(numbers.begin(), numbers.end(), g);
     vector<int> results;
     mutex mtx;
     auto start_time = chrono::high_resolution_clock::now();
    uniformPrimeSearch(start, end, numbers, results, mtx);
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end_time - start_time;

    spdlog::info("Shuffle: Found {} prime numbers in {} seconds", results.size(), duration.count());
        for (int prime : results) {
        spdlog::debug("Found prime: {}", prime);
    }
}

std::map<std::string, int> loadConfig(const std::string& filename) {
    std::map<std::string, int> config;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        spdlog::error("Не удалось открыть файл конфигурации: {}", filename);
        return config;
    }

    while (std::getline(file, line)) {
      
        size_t delimiterPos = line.find('=');
        if (delimiterPos == std::string::npos) {
              spdlog::warn("Некорректная строка в файле конфигурации: {}", line);
            continue;
        }
        std::string key = line.substr(0, delimiterPos);
        std::string valueStr = line.substr(delimiterPos + 1);

        try {
           config[key] = std::stoi(valueStr);
        }
        catch(std::invalid_argument const& ex){
            spdlog::warn("Не удалось распарсить значение: {} для ключа: {} ", valueStr, key);
            continue;
        }
    }
      if (config.find("start") == config.end() || config.find("end") == config.end() || config.find("numThreads") == config.end()) {
        spdlog::error("Отсутствуют необходимые параметры в конфигурационном файле.");
        config.clear();
    }
    
    return config;
}
