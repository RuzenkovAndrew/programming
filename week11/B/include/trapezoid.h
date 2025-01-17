#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <functional>
#include <vector>

double calculateTrapezoidArea(std::function<double(double)> func, double a, double b, int n, int numThreads);

#endif
