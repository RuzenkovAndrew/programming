#include <iostream>
#include <set>
#include <ctime>
#include "../include/order.h"
#include "../include/customer.h"
#include "../include/product.h"
#include "../include/date.h"

using namespace std;

int main() {
    Customer customer(1);

    // Создаем набор продуктов для первого заказа
    set<Product> firstOrderProducts = {
        Product(1, "Конфеты", "Сладости", 10.0),
        Product(2, "Шоколад", "Сладости", 20.0),
        Product(3, "Пряники", "Сладости", 25.0)
    };

    // Создаем набор продуктов для второго заказа
    set<Product> secondOrderProducts = {
        Product(4, "Хлеб", "Выпечка", 6.0),
        Product(5, "Булка с сыром", "Выпечка", 8.0),
        Product(6, "Вода", "Напитки", 5.0)
    };

    // Создаем заказы
    Order orders[] = {
        Order(1, date(2020, 2, 16), date(2020, 2, 20), "completed", customer, firstOrderProducts),
        Order(2, date(2020, 4, 15), date(2020, 4, 20), "completed", customer, secondOrderProducts),
        Order(3, date(2020, 3, 14), date(2020, 3, 18), "completed", customer, secondOrderProducts),
        Order(4, date(2020, 2, 14), date(2020, 2, 18), "completed", customer, secondOrderProducts)
    };

    double totalSum = 0.0;

    // Суммируем цены продуктов для заказов в феврале 2020 года
    for (const auto& order : orders) {
        time_t orderDateTime = order.getOrderDate();
        tm* orderDate = localtime(&orderDateTime);

        // Проверяем, если год 2020 и месяц 2 (февраль)
        if (orderDate->tm_year == 2020 - 1900 && orderDate->tm_mon == 1) {
            for (const auto& product : order.getProducts()) {
                totalSum += product.getPrice();
            }
        }
    }

    cout << "Сумма цен продуктов в заказах февраля 2020 года: " << totalSum << endl;

    return 0;
}

