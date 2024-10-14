#include <iostream>
#include "../include/mergeSort.hpp"
using namespace std;

int main() 
{
    int arr[] = {12, 11, 13, 5, 6, 2}; // Исходный массив
    int arrSize = sizeof(arr) / sizeof(arr[0]); // Определение размера массива

    cout << "Исходный массив: ";
    printArray(arr, arrSize); // Вывод исходного массива

    // Сортируем массив
    mergeSort(arr, 0, arrSize - 1);

    cout << "Отсортированный массив: ";
    printArray(arr, arrSize); // Вывод отсортированного массива

    return 0;
}
