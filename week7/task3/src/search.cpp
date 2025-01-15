#include "search.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
namespace fs = filesystem;

vector<string> FileSearcher::searchByName(const string& directory, const string& filename) {
    vector<string> results;
    for (const auto& entry : fs::directory_iterator(directory)) {
        cout << "Проверка файла: " << entry.path() << endl; // Отладочная информация
        if (entry.path().filename() == filename) {
            results.push_back(entry.path().string());
        }
    }
    return results;
}

vector<string> FileSearcher::searchByContent(const string& directory, const string& keyword) {
    vector<string> results;
    
    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            ifstream file(entry.path());
            string line;
            while (getline(file, line)) {
                if (line.find(keyword) != string::npos) {
                    results.push_back(entry.path().string());
                    break;
                }
            }
        }
    }
    return results;
}

