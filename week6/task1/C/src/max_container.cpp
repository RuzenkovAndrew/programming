#include "../include/max_container.hpp"
#include <list>
#include <algorithm>

using namespace std;

int maxArea(const list<int>& heights) {
    int max_area = 0;
    int left = 0;
    int right = heights.size() - 1;
    auto it_l = heights.begin();
    auto it_r = --heights.end();

    while (left < right) {
        int current_area = min(*it_l, *it_r) * (right - left);
        max_area = max(max_area, current_area);

        if (*it_l < *it_r) {
            ++it_l;
            ++left;
        } else {
           --it_r;
            --right;
        }
    }
    return max_area;
}

