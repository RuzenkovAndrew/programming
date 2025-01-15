#include "../include/max_profit.hpp"
#include <iostream>
#include <list>
#include <sstream>
#include <string>

using namespace std;

int main() {
    cout << "Введите цены акций через запятую (например, 7,1,5,3,6,4): ";
    string input;
    getline(cin, input);

    list<int> prices;
    stringstream ss(input);
    string token;

    while (getline(ss, token, ',')) {
        prices.push_back(stoi(token));
    }

    int profit = maxProfit(prices);
    cout << "Максимальная прибыль: " << profit << endl;

    return 0;
}
