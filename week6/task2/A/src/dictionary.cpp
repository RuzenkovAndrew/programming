#include "../include/dictionary.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

void addTranslation(map<string, vector<string>>& latin_to_english,
                    const string& english_word, 
                    const vector<string>& latin_words) {
    for (const auto& latin_word : latin_words) {
        latin_to_english[latin_word].push_back(english_word);
    }
}

void printLatinToEnglishDictionary(const map<string, vector<string>>& latin_to_english) {
    for (const auto& latin_entry : latin_to_english) {
        cout << latin_entry.first << " -";
        for (const auto& english_word : latin_entry.second) {
            cout << " " << english_word;
        }
        cout << endl;
    }
}
