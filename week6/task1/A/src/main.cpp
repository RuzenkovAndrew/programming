#include "../include/entropy_calculator.hpp"
#include <iostream>
#include <list>

using namespace std;

int main() {
    int n;
    cout << "Введите количество чисел: ";
    cin >> n;

    list<int> input;
    cout << "Введите числа: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        input.push_back(num);
    }

    list<list<int>> output = perms(input);

    for (const auto& perm : output) {
        cout << "[";
        auto it = perm.begin();
        for (int i = 0; it != perm.end(); ++it, ++i) {
            cout << *it;
            if (std::next(it) != perm.end()) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
