#include "../include/Bank.hpp"
#include <iostream>

int main() {
    Bank account("123456789");
    double amount;

    // Ввод суммы для пополнения
    std::cout << "Введите сумму для пополнения счета: ";
    std::cin >> amount;
    account.deposit(amount);

    // Ввод суммы для снятия
    std::cout << "Введите сумму для снятия со счета: ";
    std::cin >> amount;
    account.withdraw(amount);

    // Вывод текущего баланса
    std::cout << "Текущий баланс: " << account.getBalance() << ".\n"; // Проверка текущего баланса

    return 0;
}
