#ifndef PRIME_CALCULATOR_HPP //Use a more descriptive name.  FUNCTIONS_HPP is too generic.
#define PRIME_CALCULATOR_HPP

#include <vector>
#include <map>
#include <string> // Add this line

// Проверка числа на простоту
bool isPrime(int n);

// Функция для работы в многозадачности с механизмом Work Stealing
void workStealing(int start, int end, std::vector<int>& results);

// Функция для равномерного распределения задач
void shuffleWork(int start, int end, std::vector<int>& results);

// Функция для запуска вычислений с Work Stealing
void runWorkStealing(int start, int end, int numThreads);

// Функция для запуска вычислений с Shuffle
void runShuffle(int start, int end, int numThreads);

// Функция для загрузки конфигурации из файла
std::map<std::string, int> loadConfig(const std::string& filename);

#endif // PRIME_CALCULATOR_HPP
