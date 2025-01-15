#include "../include/sales.hpp"
#include <iostream>
#include <map>
#include <string>

// Функция для добавления данных о продаже
void addSale(std::map<std::string, std::map<std::string, int>>& sales_database,
             const std::string& customer, const std::string& product, int quantity) {
    // Добавляем количество товара для покупателя
    sales_database[customer][product] += quantity;
}

// Функция для вывода данных о покупках
void printSales(const std::map<std::string, std::map<std::string, int>>& sales_database) {
    for (const auto& customer_entry : sales_database) {
        std::cout << customer_entry.first << ":\n";  // Имя покупателя
        for (const auto& product_entry : customer_entry.second) {
            std::cout << "  " << product_entry.first << " " << product_entry.second << "\n";  // Товар и количество
        }
    }
}
