#include "../include/max_container.hpp"
#include <iostream>
#include <list>
#include <sstream>
#include <string>

using namespace std;

int main() {
    cout << "Введите высоты через запятую (например, 1,8,6,2,5,4,8,3,7): ";
    string input;
    getline(cin, input);

    list<int> heights;
    stringstream ss(input);
    string token;

    while (getline(ss, token, ',')) {
        heights.push_back(stoi(token));
    }

    int result = maxArea(heights);
    cout << "Максимальная площадь: " << result << endl;

    return 0;
}

