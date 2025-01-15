#include <iostream>
#include <string>
#include "../include/search.hpp"

using namespace std;

int main() {
    string searchString;
    string* stringsToSearch = nullptr; // Динамический массив строк
    int count = 0;
    int capacity = 10; // Начальная емкость массива

    // Ввод искомой строки
    cout << "Что ищем: ";
    getline(cin, searchString);

    // Динамическое выделение памяти для массива строк
    stringsToSearch = new string[capacity];

    // Ввод строк для поиска
    cout << "Где ищем (введите строки, завершите ввод пустой строкой):" << endl;
    while (true) {
        string inputString;
        getline(cin, inputString);

        // Проверка на максимальную длину
        if (inputString.length() > 100) {
            cout << "Строка превышает максимальную длину в 100 символов. Попробуйте снова." << endl;
            continue;
        }

        if (inputString.empty()) break; // Завершение ввода пустой строкой

        // Увеличение емкости массива, если необходимо
        if (count >= capacity) {
            capacity *= 2; // Увеличиваем емкость вдвое
            string* newStringsToSearch = new string[capacity];
            for (int i = 0; i < count; ++i) {
                newStringsToSearch[i] = stringsToSearch[i]; // Копируем старые строки
            }
            delete[] stringsToSearch; // Освобождаем старый массив
            stringsToSearch = newStringsToSearch; // Указываем на новый массив
        }

        stringsToSearch[count] = inputString; // Сохранение строки
        count++;
    }

    // Подсчет вхождений
    int totalOccurrences = countOccurrences(searchString, stringsToSearch, count);

    // Вывод результата
    cout << "Количество вхождений: " << totalOccurrences << endl;

    // Освобождение памяти
    delete[] stringsToSearch;

    return 0;
}

