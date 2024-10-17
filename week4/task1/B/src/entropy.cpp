#include "../include/entropy.hpp"
#include <cmath>

// Функция для подсчета частоты символов
std::unordered_map<char, int> countFrequencies(const std::string& input) {
    std::unordered_map<char, int> frequencyMap;

    for (char c : input) {
        if (isprint(c)) { // Учитываем только печатаемые символы
            frequencyMap[c]++;
        }
    }

    return frequencyMap;
}

// Функция для расчета энтропии по Шеннону
double calculateEntropy(const std::unordered_map<char, int>& frequencyMap, int totalChars) {
    double entropy = 0.0;

    for (const auto& pair : frequencyMap) {
        double probability = static_cast<double>(pair.second) / totalChars;
        entropy -= probability * log2(probability);
    }

    return entropy;
}

