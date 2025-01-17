#include "../include/random_file.h"
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>

std::string generateRandomWord(std::mt19937& gen, const std::vector<char>& alphabet, int minLength = 3, int maxLength = 10) {
    std::uniform_int_distribution<int> lengthDist(minLength, maxLength);
    std::uniform_int_distribution<int> charDist(0, alphabet.size() - 1);
    int wordLength = lengthDist(gen);
    std::string word;
    for (int i = 0; i < wordLength; ++i) {
        word += alphabet[charDist(gen)];
    }
    return word;
}

void createRandomTextFile(const std::string& filename, long long fileSize) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to create file: " << filename << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<char> alphabet;

    // Заполняем алфавит строчными буквами, цифрами и пробелом
    for (char c = 'a'; c <= 'z'; ++c) alphabet.push_back(c);
    for (char c = '0'; c <= '9'; ++c) alphabet.push_back(c);
    alphabet.push_back(' ');

    std::uniform_int_distribution<int> wordsPerLineDist(5, 15);

    long long bytesWritten = 0;
    const int bufferSize = 1024 * 1024; // Буфер 1MB
    while(bytesWritten < fileSize){
        long long bytesToWrite = std::min((long long)bufferSize, fileSize-bytesWritten);
        std::string buffer = "";
        while(buffer.size() < bytesToWrite) {
            int wordsPerLine = wordsPerLineDist(gen);
            for (int i = 0; i < wordsPerLine; ++i) {
                buffer += generateRandomWord(gen, alphabet) + " ";
                if (buffer.size() >= bytesToWrite) break;
            }
            buffer += "\n"; // Новая строка после слов
        }

        file.write(buffer.c_str(), buffer.size());
        bytesWritten += buffer.size();
    }

    file.close();
    std::cout << "File '" << filename << "' created successfully (" << fileSize / (1024.0 * 1024.0 * 1024.0)  << " GB)." << std::endl;
}
