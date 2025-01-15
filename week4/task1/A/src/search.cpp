#include "../include/search.hpp"

// Функция для поиска вхождений строки в массиве строк
int countOccurrences(const std::string& searchString, std::string* stringsToSearch, int count) {
    int totalOccurrences = 0;

    // Подсчет вхождений
    for (int i = 0; i < count; ++i) {
        size_t pos = stringsToSearch[i].find(searchString);
        while (pos != std::string::npos) {
            totalOccurrences++;
            pos = stringsToSearch[i].find(searchString, pos + 1); // Поиск следующего вхождения
        }
    }

    return totalOccurrences;
}

