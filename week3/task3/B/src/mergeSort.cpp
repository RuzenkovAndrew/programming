#include <iostream>
#include "../include/mergeSort.hpp"
using namespace std;

// Функция для слияния двух подмассивов
void merge(int arr[], int left, int mid, int right) 
{
    int n1 = mid - left + 1; // Размер первого подмассива
    int n2 = right - mid;    // Размер второго подмассива

    // Создание временных массивов
    int* L = new int[n1]; // Первый подмассив
    int* R = new int[n2]; // Второй подмассив

    // Копирование данных во временные массивы L[] и R[]
    for (int i = 0; i < n1; i++) 
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) 
    {
        R[j] = arr[mid + 1 + j];
    }

    // Индексы для слияния
    int i = 0, j = 0, k = left;

    // Слияние временных массивов обратно в arr[left..right]
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i]; // Если элемент из L меньше или равен, добавляем его в arr
            i++;
        } else 
        {
            arr[k] = R[j]; // Иначе добавляем элемент из R
            j++;
        }
        k++;
    }

    // Копирование оставшихся элементов L[], если есть
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Копирование оставшихся элементов R[], если есть
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Освобождение памяти
    delete[] L;
    delete[] R;
}

// Функция сортировки слиянием
void mergeSort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        // Находим среднюю точку
        int mid = left + (right - left) / 2;

        // Рекурсивно сортируем обе половины
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Сливаем отсортированные половины
        merge(arr, left, mid, right);
    }
}

// Функция для вывода массива
void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " "; // Вывод каждого элемента массива
    }
    cout << endl;
}


