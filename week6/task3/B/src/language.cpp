#include "../include/language.hpp"
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для обработки языков
void processLanguages(int n, vector<vector<string>>& languages, set<string>& allLanguages, set<string>& commonLanguages) {
    // Вначале общими являются все языки первого школьника
    commonLanguages = set<string>(languages[0].begin(), languages[0].end());
    
    // Перебираем всех школьников
    for (int i = 1; i < n; ++i) {
        set<string> studentLanguages(languages[i].begin(), languages[i].end());
        
        // Пересекаем с текущими общими языками
        set<string> intersection;
        set_intersection(commonLanguages.begin(), commonLanguages.end(),
                              studentLanguages.begin(), studentLanguages.end(),
                              inserter(intersection, intersection.begin()));
        commonLanguages = intersection;
    }

    // Собираем все уникальные языки
    for (int i = 0; i < n; ++i) {
        allLanguages.insert(languages[i].begin(), languages[i].end());
    }
}

// Функция для сортировки и вывода
void printLanguages(const set<string>& languages) {
    for (const auto& lang : languages) {
        cout <<  lang << endl;
    }
}
