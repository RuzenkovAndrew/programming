#include "../include/duplicate_remover.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

vector<int> readArrayFromInput() {
    cout << "Введите элементы массива, разделенные пробелами (например, '1 2 3 4 2'):" << endl;
    string inputLine;
    getline(cin, inputLine);

    istringstream iss(inputLine);
    vector<int> numbers;
    int number;
    while(iss >> number) {
        numbers.push_back(number);
    }
    return numbers;
}

int main() {
    vector<int> inputArray = readArrayFromInput();

    cout << "Исходный массив: ";
    copy(inputArray.begin(), inputArray.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> result = removeDuplicates(inputArray);

    cout << "Массив без дубликатов: ";
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
