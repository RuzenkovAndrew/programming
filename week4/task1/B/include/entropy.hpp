
#include <unordered_map>
#include <string>

// Функция для подсчета частоты символов
std::unordered_map<char, int> countFrequencies(const std::string& input);

// Функция для расчета энтропии по Шеннону
double calculateEntropy(const std::unordered_map<char, int>& frequencyMap, int totalChars);

