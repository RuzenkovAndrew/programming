#include "../include/typeConverter.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

void convertToFloat(const string& input) {
    try {
        int intValue = stoi(input);
        float floatValue = static_cast<float>(intValue);
        cout << "Преобразованное значение (целое в число с плавающей точкой): " << floatValue << endl;
    } catch (const invalid_argument&) {
        cout << "Ошибка: Невозможно преобразовать строку \"" << input << "\" в целое число." << endl;
    }
}

void convertToInt(const string& input) {
    try {
        float floatValue = stof(input);
        // Потеря данных при преобразовании
        int intValue = static_cast<int>(floatValue);
        cout << "Преобразованное значение (число с плавающей точкой в целое): " << intValue
             << " (потеря данных!)" << endl;
    } catch (const invalid_argument&) {
        cout << "Ошибка: Невозможно преобразовать строку \"" << input << "\" в число с плавающей точкой." << endl;
    }
}

void convertCharToASCII(const string& input) {
    if (input.length() == 1) {
        char character = input[0];
        int asciiValue = static_cast<int>(character);
        cout << "Преобразованное значение (символ в ASCII-код): " << asciiValue << endl;
    } else {
        cout << "Ошибка: Пожалуйста, введите только один символ." << endl;
    }
}

void convertASCIIToChar(const string& input) {
    try {
        int asciiValue = stoi(input);
        if (asciiValue >= 0 && asciiValue <= 255) {
            char character = static_cast<char>(asciiValue);
            cout << "Преобразованное значение (ASCII-код в символ): " << character << endl;
        } else {
            cout << "Ошибка: ASCII-код должен быть в диапазоне от 0 до 255." << endl;
        }
    } catch (const invalid_argument&) {
        cout << "Ошибка: Невозможно преобразовать строку \"" << input << "\" в число." << endl;
    }
}


