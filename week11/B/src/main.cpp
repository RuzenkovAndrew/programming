#include <iostream>
#include "../include/trapezoid.h"
#include "../include/function.h"
#include <chrono>
#include <thread>

int main() {
    double a, b;
    int n;

    std::cout << "Enter the lower bound (a): ";
    std::cin >> a;
    std::cout << "Enter the upper bound (b): ";
    std::cin >> b;
    std::cout << "Enter the number of trapezoids (n): ";
    std::cin >> n;

    int numThreads = std::thread::hardware_concurrency();
     if(numThreads == 0) numThreads = 4;
    auto start = std::chrono::high_resolution_clock::now();
    double area = calculateTrapezoidArea(exampleFunction, a, b, n, numThreads);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Time: " << duration.count() << " seconds" << std::endl;
    std::cout << "Area: " << area << std::endl;

    return 0;
}
