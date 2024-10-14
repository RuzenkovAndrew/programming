#include <iostream>
#include "../include/pyramid.hpp"

using namespace std;

int main() 
{
    int height;
    cout << "Введите высоту пирамиды: ";
    cin >> height;

    pyramid(height);

    return 0;
}

