#include "../include/calculate.hpp"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string input;
    cout << "Введите пакет показаний с датчиков: ";
    getline(cin, input);

    SensorData sensors[256]; // Массив для хранения данных о датчиках
    int sensorCount = 0;
    bool hasErrors = false;

    // Рассчитываем температуры
    calculateTemperatures(input, sensors, sensorCount, hasErrors);

    // Запрашиваем, по какому полю сортировать
    int choice;
    cout << "Выберите поле для сортировки:\n1. По ID датчика\n2. По температуре\nВаш выбор: ";
    cin >> choice;

    bool sortById = (choice == 1);

    // Сортируем датчики
    sortSensors(sensors, sensorCount, sortById);

    // Выводим результаты
    cout << fixed << setprecision(1);
    if (hasErrors) {
        cout << "Обнаружены ошибки, результат может быть некорректным." << endl;
    }
    for (int i = 0; i < sensorCount; ++i) {
        cout << sensors[i].id << " " << sensors[i].temperature << endl; // Выводим последнее значение температуры
    }

    return 0;
}



