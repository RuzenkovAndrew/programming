#include "../include/trapezoid.h"
#include <thread>
#include <vector>
#include <numeric>
#include <cmath>

double calculatePartialArea(std::function<double(double)> func, double a, double b, int n, int thread_id, int numThreads) {
    double h = (b - a) / n;
    double partialArea = 0.0;
    int start = thread_id;
    for(int i = start; i < n; i+=numThreads){
         double x1 = a + i * h;
         double x2 = a + (i+1)*h;
         partialArea += (func(x1) + func(x2)) / 2.0 * h;
    }
    return partialArea;
}


double calculateTrapezoidArea(std::function<double(double)> func, double a, double b, int n, int numThreads) {
   std::vector<std::thread> threads;
   std::vector<double> partialAreas(numThreads);
   for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back([&, i] {
            partialAreas[i] = calculatePartialArea(func, a, b, n, i, numThreads);
        });
   }

    for (auto& thread : threads) {
        thread.join();
    }

    return std::accumulate(partialAreas.begin(), partialAreas.end(), 0.0);
}
