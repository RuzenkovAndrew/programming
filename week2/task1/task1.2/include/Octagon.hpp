#ifndef OCTAGON_HPP
#define OCTAGON_HPP

#include <cmath>

class Octagon {
private:
  double innerRadius;

public:
  void setInnerRadius(double radius) {
    innerRadius = radius;
  }

  double calculateArea() {
    double length = 2 * innerRadius / (1 + sqrt(2));
    return 2 * (1 + sqrt(2)) * pow(length, 2);
  }

  double calculatePerimeter() {
    double length = 2 * innerRadius / (1 + sqrt(2));
    return 8 * length;
  }
};

#endif // OCTAGON_HPP
