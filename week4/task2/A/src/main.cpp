#include <iostream>
#include <string>
#include "../include/email_validator.hpp"

using namespace std;

int main() {
    string email;
    while (true) {
        // Ввод адреса электронной почты
        cout << "Введите адрес электронной почты: ";
        getline(cin, email);
    
        // Проверка корректности адреса электронной почты
        if (isValidEmail(email)) {
            cout << "Адрес электронной почты корректен." << endl;
            break;
        } else {
            cout << "Некорректный адрес электронной почты." << endl;
        }
    }

    return 0;
}
