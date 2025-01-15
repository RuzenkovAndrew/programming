#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "../include/language.hpp"

using namespace std;

int main() {
    int n;  // количество школьников
    cin >> n;
    
    vector<vector<string>> languages(n);
    
    // Чтение языков для каждого школьника
    for (int i = 0; i < n; ++i) {
        int k;  // количество языков, которое знает i-й школьник
        cin >> k;
        
        languages[i].resize(k);
        
        for (int j = 0; j < k; ++j) {
            cin >> languages[i][j];
        }
    }

    // Множества для хранения языков
    set<string> allLanguages;  // Языки, которые знает хотя бы один школьник
    set<string> commonLanguages;  // Языки, которые знают все школьники
    
    // Обработка данных
    processLanguages(n, languages, allLanguages, commonLanguages);

    // Вывод результатов
    cout << "\n\n" << commonLanguages.size() << endl;
    printLanguages(commonLanguages);
    
    cout << allLanguages.size() << endl;
    printLanguages(allLanguages);

    return 0;
}
