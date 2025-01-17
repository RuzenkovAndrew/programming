#include "../include/entropy.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <map>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mtx;
std::map<char, long long> globalCharCounts;

double calculatePartialEntropy(const std::string& filename, long long start, long long end) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file: " << filename << std::endl;
        return 0.0; // Return 0 in case of error
    }
    file.seekg(start);
    std::map<char, long long> localCharCounts;

    long long bytesRead = 0;
    char buffer[1024];

    while(bytesRead < end-start) {
        long long bytesToRead = std::min((long long)sizeof(buffer), end - start - bytesRead );
        file.read(buffer, bytesToRead);
        bytesRead += bytesToRead;
        for (int i = 0; i < bytesToRead; ++i) {
            localCharCounts[buffer[i]]++;
        }
    }
    file.close();
    std::lock_guard<std::mutex> lock(mtx);

    for(auto const& [key, val] : localCharCounts){
        globalCharCounts[key] += val;
    }
    return 0.0;
}

double calculateEntropy(const std::string& filename) {
    globalCharCounts.clear();
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file: " << filename << std::endl;
        return 0.0;
    }

    long long fileSize = file.tellg();
    file.close();

    int numThreads = std::thread::hardware_concurrency();
    if(numThreads == 0) numThreads = 4; // just in case
    std::vector<std::thread> threads;

    long long chunkSize = fileSize / numThreads;

    for (int i = 0; i < numThreads; ++i) {
        long long start = i * chunkSize;
        long long end = (i == numThreads - 1) ? fileSize : (i + 1) * chunkSize;
        threads.emplace_back(calculatePartialEntropy, filename, start, end);
    }

    for (auto& thread : threads) {
        thread.join();
    }
    double entropy = 0.0;
    long long totalChars = 0;
    for(auto const& [key, val] : globalCharCounts){
        totalChars += val;
    }

    for(auto const& [key, val] : globalCharCounts){
        double p = static_cast<double>(val) / totalChars;
        entropy -= p * std::log2(p);
    }

    return entropy;
}
