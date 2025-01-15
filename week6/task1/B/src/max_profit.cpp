#include "../include/max_profit.hpp"
#include <list>
#include <algorithm>
#include <limits>

using namespace std;

int maxProfit(const list<int>& prices) {
    int minPrice = numeric_limits<int>::max();
    int maxProfit = 0;

    for (int price : prices) {
        if (price < minPrice) {
            minPrice = price;
        } else {
            maxProfit = max(maxProfit, price - minPrice);
        }
    }
    return maxProfit;
}
