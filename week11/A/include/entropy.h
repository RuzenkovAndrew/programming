#ifndef ENTROPY_H
#define ENTROPY_H

#include <string>
#include <vector>

double calculateEntropy(const std::string& filename);
double calculatePartialEntropy(const std::string& filename, long long start, long long end);
#endif
