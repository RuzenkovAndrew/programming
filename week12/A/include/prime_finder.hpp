#pragma once

#include <vector>
#include <map>
#include <string> // Added this line

bool isPrime(int n);
void runWorkStealing(int start, int end, int numThreads);
void runShuffle(int start, int end, int numThreads);
std::map<std::string, int> loadConfig(const std::string& filename);
