#include "../include/sales.hpp"
#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main() {
    int N;
    cout << "Введите количество строк данных о продажах: ";
    cin >> N;
    cin.ignore();  // Игнорируем символ новой строки после числа N

    // Словарь для хранения данных о продажах
    map<string, map<string, int>> sales_database;

    cout << "Введите строки данных о продажах: ";   // Чтение данных
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);

        // Разделяем строку на покупателя, товар и количество
        stringstream ss(line);
        string customer, product;
        int quantity;
        
        ss >> customer >> product >> quantity;

        // Добавляем данные о продаже
        addSale(sales_database, customer, product, quantity);
    }

    // Выводим данные о продажах
    printSales(sales_database);

    return 0;
}

