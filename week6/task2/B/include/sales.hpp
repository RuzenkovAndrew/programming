#include <string>
#include <map>

// Функция для добавления данных о продаже
void addSale(std::map<std::string, std::map<std::string, int>>& sales_database,
             const std::string& customer, const std::string& product, int quantity);

// Функция для вывода данных о покупках
void printSales(const std::map<std::string, std::map<std::string, int>>& sales_database);

