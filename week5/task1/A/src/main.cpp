#include <iostream>
#include "../include/calculations.hpp"

int main(int argc, char* argv[]) {
    // Проверяем, передан ли аргумент с именем файла
    if (argc < 2) {
        std::cerr << "Ошибка: Необходимо указать путь к файлу." << std::endl;
        return 1; // Завершаем программу с ошибкой
    }

    std::string filename = argv[1]; // Имя файла для чтения из аргументов
    readFile(filename); // Читаем файл
    return 0; // Успешное завершение программы
}
