#include <iostream>
#include <string>

using namespace std;

int main() {
    const int MAX_STRINGS = 100; // Максимальное количество строк
    const int MAX_LENGTH = 100;  // Максимальная длина строки

    string searchString;
    string stringsToSearch[MAX_STRINGS];
    int count = 0;

    // Ввод искомой строки
    cout << "Что ищем: ";
    getline(cin, searchString);

    // Ввод строк для поиска
    cout << "Где ищем (введите строки, завершите ввод пустой строкой):" << endl;
    for (int i = 0; i < MAX_STRINGS; ++i) {
        string inputString;
        getline(cin, inputString);

        // Проверка на максимальную длину
        if (inputString.length() > MAX_LENGTH) {
            cout << "Строка превышает максимальную длину в " << MAX_LENGTH << " символов. Попробуйте снова." << endl;
            i--; // Повторить ввод для этой строки
            continue;
        }

        if (inputString.empty()) break; // Завершение ввода пустой строкой
        stringsToSearch[i] = inputString; // Сохранение строки
        count++;
    }

    int totalOccurrences = 0;

    // Подсчет вхождений
    for (int i = 0; i < count; ++i) {
        size_t pos = stringsToSearch[i].find(searchString);
        while (pos != string::npos) {
            totalOccurrences++; 
            pos = stringsToSearch[i].find(searchString, pos + 1); // Поиск следующего вхождения
        }
    }

    // Вывод результата
    cout << "Количество вхождений: " << totalOccurrences << endl;

    return 0;
}

