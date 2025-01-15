#ifndef CAR_HPP
#define CAR_HPP

#include <string>
#include "Engine.hpp"
#include "Passenger.hpp"

class Car {
private:
    std::string model; // Модель автомобиля
    Engine engine; // Двигатель автомобиля
    Passenger* passenger1; // Первый пассажир
    Passenger* passenger2; // Второй пассажир

public:
    // Конструктор автомобиля
    Car(std::string carModel, Engine carEngine) 
        : model(carModel), engine(carEngine), passenger1(nullptr), passenger2(nullptr) {}

    // Метод для добавления пассажира
    void addPassenger(Passenger* passenger);

    // Метод для удаления пассажира
    void removePassenger(Passenger* passenger);

    // Метод для вывода информации об автомобиле
    void displayInfo() const;
};

#endif // CAR_HPP

