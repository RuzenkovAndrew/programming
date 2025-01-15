#ifndef Bank_HPP
#define Bank_HPP

#include <string>

class Bank {
private:
    std::string accountNumber; // Номер счета
    double balance; // Приватное поле для хранения баланса

public:
    // Конструктор
    Bank(const std::string& accNum);
    
    // Метод для пополнения счета
    void deposit(double amount);
    
    // Метод для снятия суммы со счета
    void withdraw(double amount);
    
    // Метод для получения текущего баланса
    double getBalance() const;
};

#endif // Bank_HPP
