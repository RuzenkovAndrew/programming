#ifndef CALCULATE_HPP
#define CALCULATE_HPP

#include <string>
#include <stdexcept>

struct SensorData {
    int id;
    double temperature; // Сохраним последнее значение температуры
};

// Исключение для пустой строки
class EmptyInputException : public std::runtime_error {
public:
    EmptyInputException() : std::runtime_error("Ошибка: Введена пустая строка или строка состоит только из пробелов.") {}
};

// Исключение для выхода температуры за пределы диапазона
class TemperatureOutOfRangeException : public std::runtime_error {
public:
    TemperatureOutOfRangeException(double temperature)
        : std::runtime_error("Ошибка: Значение температуры " + std::to_string(temperature) + " вышло за пределы диапазона.") {}
};

void calculateTemperatures(const std::string& input, SensorData sensors[], int& sensorCount, bool& hasErrors);
void sortSensors(SensorData sensors[], int sensorCount, bool sortById);

#endif // CALCULATE_HPP


