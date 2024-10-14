#include <cmath> 

// Функция для вычисления квадратного корня методом Герона
double heron_sqrt(double number, double epsilon = 1e-6) 
{
    double guess = 1.0; // Начальное приближение

    while (abs(guess * guess - number) > epsilon) 
    { // Формула Герона
        guess = (guess + number / guess) / 2; // Обновление предположения
    }

    return guess;
}
