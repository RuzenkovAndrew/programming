#include <string>
#include <vector>
#include <map>

// Функция для добавления перевода в словарь
void addTranslation(std::map<std::string, std::vector<std::string>>& latin_to_english,
                    const std::string& english_word, 
                    const std::vector<std::string>& latin_words);

// Функция для вывода латинско-английского словаря
void printLatinToEnglishDictionary(const std::map<std::string, std::vector<std::string>>& latin_to_english);

