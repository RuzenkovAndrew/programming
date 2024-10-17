#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    // Регулярное выражение для проверки адреса электронной почты
    const regex emailPattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");

    string email;
    while(true){
        // Ввод адреса электронной почты
        cout << "Введите адрес электронной почты: ";
        getline(cin, email);
    
        // Проверка соответствия регулярному выражению
        if (regex_match(email, emailPattern)) {
            cout << "Адрес электронной почты корректен." << endl;
            break;
        } else {
            cout << "Некорректный адрес электронной почты." << endl;
        }
    }

    return 0;
}

