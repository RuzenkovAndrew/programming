#include <iostream>
#include "../include/heron_sqrt.hpp"

using namespace std;

int main() 
{
    double number;
    cout << "Введите число: ";
    cin >> number;

    double sqrt = heron_sqrt(number);
    cout << "Квадратный корень из " << number << " равен " << sqrt << endl;

    return 0;
}
