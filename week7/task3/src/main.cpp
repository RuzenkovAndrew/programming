#include <iostream>
#include "search.hpp"

using namespace std;

int main() {
    string directory;
    cout << "Введите путь к директории: ";
    cin >> directory;

    string filename;
    cout << "Введите имя файла для поиска: ";
    cin >> filename;
    auto filesByName = FileSearcher::searchByName(directory, filename);
    
    cout << "Найденные файлы по имени:\n";
    for (const auto& file : filesByName) {
        cout << file << endl;
    }

    string keyword;
    cout << "Введите ключевое слово для поиска в содержимом: ";
    cin >> keyword;
    auto filesByContent = FileSearcher::searchByContent(directory, keyword);
    
    cout << "Найденные файлы по содержимому:\n";
    for (const auto& file : filesByContent) {
        cout << file << endl;
    }

    return 0;
}

