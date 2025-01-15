#include <iostream>
#include "../include/frequency.hpp"

using namespace std;

int main() {
    string input;
    cout << "Введите строку: ";
    getline(cin, input); 

    auto frequency = countCharacterFrequency(input);

    auto [maxChar, maxCount] = findMaxFrequencyCharacter(frequency);

    // Вывод результата
    if (maxCount > 0) {
        cout << "Результат: ['" << maxChar << "', " << maxCount << "]" << endl;
    } else {
        cout << "Строка пуста." << endl;
    }

    return 0; 
}


