#include <iostream>
using namespace std;

// Функция для вывода возраста
void printAge(int age) 
{
    if (-1 < age && age < 21) 
    {
        if (age == 0) 
        {
            cout << age << " лет" << endl;
        } 
        else if (age == 1) 
        {
            cout << age << " год" << endl;
        } 
        else if (age >= 2 && age <= 4) 
        {
            cout << age << " года" << endl;
        } 
        else 
        {
            cout << age << " лет" << endl;
        }
    } 
    else if (age > 20) 
    {
        int number = age % 10; // Получаем остаток от деления на 10 (единицы)
        if (number == 1) 
        {
            cout << age << " год" << endl;
        } 
        else if (number == 0 || (number >= 5 && number <= 9)) 
        {
            cout << age << " лет" << endl;
        } 
        else 
        {
            cout << age << " года" << endl;
        }
    } 
    else 
    {
        cout << "Возраст должен быть больше -1" << endl;
    }
}
