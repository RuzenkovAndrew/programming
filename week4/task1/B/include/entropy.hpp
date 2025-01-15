#ifndef ENTROPY_HPP
#define ENTROPY_HPP

#include <string>

// Максимальное количество символов (ASCII)
const int MAX_CHAR = 256;

// Функция для подсчета частоты символов
void countFrequencies(const std::string& input, int frequencyMap[MAX_CHAR]);

// Функция для расчета энтропии по Шеннону
double calculateEntropy(const int frequencyMap[MAX_CHAR], int totalChars);

#endif // ENTROPY_HPP

