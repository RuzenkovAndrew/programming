#include <iostream>
#include <string>
#include <iomanip>
#include "../include/entropy.hpp"

using namespace std;

int main() {
    string input;

    // Ввод строки
    cout << "Введите строку: ";
    getline(cin, input);

    // Проверка на пустую строку
    if (input.empty()) {
        cout << "Строка пуста. Энтропия не может быть рассчитана." << endl;
        return 1;
    }

    // Подсчет частоты символов
    int frequencyMap[MAX_CHAR];
    countFrequencies(input, frequencyMap);
    int totalChars = input.length(); // Общее количество символов

    // Расчет энтропии
    double entropy = calculateEntropy(frequencyMap, totalChars);

    // Вывод результата с двумя знаками после запятой
    cout << fixed << setprecision(2) << entropy << endl;

    return 0;
}

