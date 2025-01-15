#include "../include/duplicate_remover.hpp"
#include <set>

std::vector<int> removeDuplicates(const std::vector<int>& input) {
    std::set<int> uniqueElements;
    for (int num : input) {
        uniqueElements.insert(num);
    }
    return std::vector<int>(uniqueElements.begin(), uniqueElements.end());
}

