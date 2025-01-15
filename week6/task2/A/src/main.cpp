#include "../include/dictionary.hpp"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int N;
    cout << "Введите количество слов в словаре: ";
    cin >> N;
    cin.ignore();  // Игнорируем символ новой строки после числа N

    // Словарь для латинских слов
    map<string, vector<string>> latin_to_english;

    // Чтение словаря
    for (int i = 0; i < N; ++i) {
        string english_word;
        cout << "Введите слова: ";
        cin >> english_word; // Считываем английское слово

        string delimiter;
        cin >> delimiter; // Считываем дефис (входной формат)

        string latin_word;
        vector<string> latin_words;
        
        // Чтение латинских слов, разделенных запятой
        while (cin.peek() != '\n' && cin >> latin_word) {
            latin_words.push_back(latin_word);
            if (cin.peek() == ',') { // Если следующий символ - запятая, пропускаем её
                cin.ignore();
            }
        }

        // Добавляем переводы в словарь
        addTranslation(latin_to_english, english_word, latin_words);
    }

    // Вывод латинско-английского словаря
    printLatinToEnglishDictionary(latin_to_english);

    return 0;
}
