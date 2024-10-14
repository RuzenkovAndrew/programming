#include <iostream>
#include "../include/printAge.hpp"

using namespace std;

int main() 
{
    int age;
    cout << "Введите возраст: ";
    cin >> age;

    printAge(age);

    return 0;
}
