#include <iostream>
#include <cmath> // Для sqrt и pow

int main() {
    double edgeLength;
    std::cout << "Введите длину ребра икосаэдра: ";
    std::cin >> edgeLength;

    // Формула для объема икосаэдра: V = (5 * (3 + sqrt(5))) / 12 * a^3
    // где a - длина ребра икосаэдра.
    double volume = (5.0 * (3.0 + sqrt(5.0))) / 12.0 * pow(edgeLength, 3);
    
    std::cout << "Объем икосаэдра: " << volume << std::endl;

    return 0;
}
