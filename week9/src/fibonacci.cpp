#include "../include/fibonacci.hpp"
#include <map>
using namespace std;

// Глобальный кеш для оптимизированной версии
map<int, long long> cache;

long long classic(int n) {
    if (n < 0) {
        return 0;
    }
    if (n <= 1) return n;
    return classic(n - 1) + classic(n - 2);
}

long long optimized(int n) {
    if (n < 0) {
        return 0;
    }
    if (n <= 1) return n;

    // Проверка наличия в кеше
    if (cache.find(n) != cache.end()) {
        return cache[n];
    }

    // Вычисление и сохранение в кеше
    cache[n] = optimized(n - 1) + optimized(n - 2);
    return cache[n];
}
