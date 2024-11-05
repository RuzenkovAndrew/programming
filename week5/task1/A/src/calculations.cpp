#include "../include/calculations.hpp"
#include <iostream>
#include <fstream>

void readFile(const std::string& filename) {
    std::ifstream file(filename); // Открываем файл для чтения

    // Проверяем, открылся ли файл
    if (!file.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл " << filename << std::endl;
        return; // Возвращаем из функции в случае ошибки
    }

    std::string line;
    // Читаем строки из файла
    while (getline(file, line)) {
        std::cout << line << std::endl; 
    }

    // Проверяем, произошла ли ошибка при чтении
    if (file.bad()) {
        std::cerr << "Ошибка при чтении файла " << filename << std::endl;
    }

    file.close(); // Закрываем файл после завершения чтения
}


