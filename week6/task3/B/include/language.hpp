#include <vector>
#include <string>
#include <set>

// Функция для обработки данных школьников и их языков
void processLanguages(int n, std::vector<std::vector<std::string>>& languages, 
                      std::set<std::string>& allLanguages, std::set<std::string>& commonLanguages);

// Функция для сортировки и вывода данных
void printLanguages(const std::set<std::string>& languages);

