#include <iostream>
#include <string>
#include "../include/memory.h"
#include "../include/random_file.h"
#include "../include/entropy.h"

int main() {
    long long totalMemory = getSystemMemory();
    if (totalMemory == 0) {
        std::cerr << "Error: Could not get memory size." << std::endl;
        return 1;
    }

    long long fileSizeBytes = totalMemory * 2;
    std::string filename = "random_text_file.txt";
    createRandomTextFile(filename, fileSizeBytes);

    double entropy = calculateEntropy(filename);

    std::cout << "Entropy: " << entropy << std::endl;

    if (std::remove(filename.c_str()) == 0){ // удаление файла
        std::cout << "Removed " << filename << std::endl;
    } else {
        std::cerr << "Cant delete file " << filename << std::endl;
    }

    return 0;
}
