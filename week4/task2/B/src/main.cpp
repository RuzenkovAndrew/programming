#include <iostream>
#include <string>
#include "../include/ipv6_checker.hpp"

using namespace std;

int main() {
    string input;

    // Ввод адреса IPv6
    cout << "Введите адрес IPv6 в полной форме: ";
    getline(cin, input);

    // Проверка и вывод результата
    if (isValidIPv6(input)) {
        cout << "Адрес IPv6 корректен." << endl;
    } else {
        cout << "Адрес IPv6 некорректен." << endl;
    }

    return 0;
}

