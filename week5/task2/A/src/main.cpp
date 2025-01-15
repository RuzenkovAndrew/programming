#include <iostream>
#include <string>
#include "../include/typeConverter.hpp"

using namespace std;

int main() {
    string input;
    int choice;

    cout << "Введите сообщение: ";
    getline(cin, input);

    cout << "Выберите тип преобразования:\n";
    cout << "1. Целое число в число с плавающей точкой\n";
    cout << "2. Число с плавающей точкой в целое(будет утеряна часть данных\n";
    cout << "3. Символ в его ASCII-код\n";
    cout << "4. ASCII-код в символ(В диапазоне 0-255)\n";
    cout << "Ваш выбор (1-4): ";
    cin >> choice;

    switch (choice) {
        case 1:
            convertToFloat(input);
            break;
        case 2:
            convertToInt(input);
            break;
        case 3:
            convertCharToASCII(input);
            break;
        case 4:
            convertASCIIToChar(input);
            break;
        default:
            cout << "Ошибка: Неверный выбор." << endl;
            break;
    }

    return 0; // Успешное завершение программы
}





