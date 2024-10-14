#include <iostream>
#include "../include/days_in_month.hpp"

using namespace std;

int main() {
    int year, month;
    cout << "Введите год: ";
    cin >> year;
    cout << "Введите номер месяца (1-12): ";
    cin >> month;

    int daysInMonth = getDaysInMonth(year, month);

    cout << "В " << month << " месяце " << year << " года " << daysInMonth << " дней." << endl;

    return 0;
}


