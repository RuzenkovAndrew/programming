#include <iostream>
#include <fstream>
#include <string>
#include "../include/entropy_calculator.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    // Проверка количества аргументов командной строки
    if (argc != 2) {
        cerr << "Ошибка: Укажите имя файла в качестве аргумента." << endl;
        return 1;
    }

    string filename = argv[1]; // Имя файла из аргументов командной строки
    ifstream file(filename, ios::binary); // Открываем файл для чтения в бинарном режиме

    // Проверка, открылся ли файл
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл " << filename << endl;
        return 1;
    }

    int frequency[256] = {0}; // Массив для частоты символов ASCII
    int totalChars = 0;
    const size_t BUFFER_SIZE = 4096; // Размер буфера для чтения

    // Чтение файла частями
    char buffer[BUFFER_SIZE];
    while (file.read(buffer, BUFFER_SIZE) || file.gcount() > 0) {
        size_t bytesRead = file.gcount();
        for (size_t i = 0; i < bytesRead; i++) {
            frequency[(unsigned char)buffer[i]]++;
            totalChars++;
        }
    }

    // Проверка на наличие символов в файле
    if (totalChars == 0) {
        cerr << "Ошибка: Файл пустой." << endl;
        return 1;
    }

    file.close(); // Закрываем файл после завершения чтения

    // Вычисление и вывод энтропии
    double entropy = calculateShannonEntropy(frequency, totalChars);
    cout << "Энтропия по Шеннону: " << entropy << endl;

    return 0; // Успешное завершение программы
}

