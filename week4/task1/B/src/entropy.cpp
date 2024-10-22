#include "../include/entropy.hpp"
#include <cmath>
#include <cctype>

// Функция для подсчета частоты символов
void countFrequencies(const std::string& input, int frequencyMap[MAX_CHAR]) {
    // Инициализация массива частоты
    for (int i = 0; i < MAX_CHAR; ++i) {
        frequencyMap[i] = 0;
    }

    for (char c : input) {
        if (isprint(c)) { // Учитываем только печатаемые символы
            frequencyMap[static_cast<unsigned char>(c)]++;
        }
    }
}

// Функция для расчета энтропии по Шеннону
double calculateEntropy(const int frequencyMap[MAX_CHAR], int totalChars) {
    double entropy = 0.0;

    for (int i = 0; i < MAX_CHAR; ++i) {
        if (frequencyMap[i] > 0) {
            double probability = static_cast<double>(frequencyMap[i]) / totalChars;
            entropy += probability * log2(probability); // 
        }
    }

    return -entropy; // Отрицательное значение энтропии возвращаем здесь
}

