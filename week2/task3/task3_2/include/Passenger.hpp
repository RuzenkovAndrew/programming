#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include <string>

class Passenger {
private:
    std::string name; // Имя пассажира

public:
    // Конструктор пассажира
    Passenger(std::string passengerName) : name(passengerName) {}

    // Метод для получения имени пассажира
    std::string getName() const { return name; }
};

#endif // PASSENGER_HPP

