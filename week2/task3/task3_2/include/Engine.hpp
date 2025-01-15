#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <string>

class Engine {
private:
    int power; // Мощность двигателя

public:
    // Конструктор двигателя
    Engine(int enginePower) : power(enginePower) {}

    // Метод для получения мощности двигателя
    int getPower() const { return power; }
};

#endif // ENGINE_HPP

