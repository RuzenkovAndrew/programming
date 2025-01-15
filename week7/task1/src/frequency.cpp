#include "../include/frequency.hpp"

using namespace std;

unordered_map<char, int> countCharacterFrequency(const string& input) {
    unordered_map<char, int> frequency; // Для хранения частоты символов

    // Подсчет частоты символов
    for (char c : input) {
        frequency[c]++;
    }
    return frequency;
}

pair<char, int> findMaxFrequencyCharacter(const unordered_map<char, int>& frequency) {
    char maxChar = '\0';
    int maxCount = 0;

    // Нахождение символа с максимальной частотой
    for (const auto& pair : frequency) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            maxChar = pair.first;
        }
    }
    return {maxChar, maxCount};
}

