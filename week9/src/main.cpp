#include <iostream>
#include <ctime>
#include "../include/fibonacci.hpp"

using namespace std;

void measureTime(int n) {
    clock_t start, end;

    start = clock();
    long long classicResult = classic(n);
    end = clock();
    double classicDuration = double(end - start) / CLOCKS_PER_SEC;

    start = clock();
    long long optimizedResult = optimized(n);
    end = clock();
    double optimizedDuration = double(end - start) / CLOCKS_PER_SEC;

    cout << "Fibonacci(" << n << ") = " << classicResult << " (classic) in " << classicDuration << " seconds\n";
    cout << "Fibonacci(" << n << ") = " << optimizedResult << " (optimized) in " << optimizedDuration << " seconds\n";
}

int main() {
    for (int n = 0; n <= 40; n += 5) {
        measureTime(n);
    }
    return 0;
}
