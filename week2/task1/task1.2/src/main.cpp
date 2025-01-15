#include <iostream>
#include "../include/Octagon.hpp"

using namespace std;

int main() {
  Octagon octagon;

  double radius;
  cout << "Введите внутренний радиус: ";
  cin >> radius;
  octagon.setInnerRadius(radius);

  cout << "Площадь: " << octagon.calculateArea() << endl;
  cout << "Периметр: " << octagon.calculatePerimeter() <<  endl;

  return 0;
}
