#include "password_cracker.hpp"
#include <iostream>

int main() {
    std::string targetPassword;
    std::cout << "Введите пароль для подбора: ";
    std::cin >> targetPassword;

    // Вычисляем MD5 хэш для введенного пароля
    unsigned char result[MD5_DIGEST_LENGTH];
    computeMD5FromString(targetPassword, result);
    std::string targetMD5 = md5ToString(result);

    // Перебираем количество потоков от 1 до 10
    for (int numThreads = 1; numThreads <= 10; ++numThreads) {
        std::cout << "Запуск с " << numThreads << " потоками..." << std::endl;
        bruteForceMD5(targetMD5, numThreads, targetPassword);
    }

    return 0;
}

