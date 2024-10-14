#include <iostream>
#include "../include/max_element.hpp"

using namespace std;

int main() 
{
    int arr;
    cout << "Введите размер массива: ";
    cin >> arr;

    int numbers[arr];
    cout << "Введите элементы массива: ";
    for (int i = 0; i < arr; i++) 
    {
        cin >> numbers[i];
    }

    int maxElement = 0;
    int count = 0;

    max_element(numbers, arr, maxElement, count);

    cout << "Наибольший элемент: " << maxElement << endl;
    cout << "Количество таких же элементов: " << count << endl;

    return 0;
}

