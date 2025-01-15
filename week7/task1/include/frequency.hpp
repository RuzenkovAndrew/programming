#ifndef FREQUENCY_HPP
#define FREQUENCY_HPP

#include <string>
#include <unordered_map>
#include <utility> 

using namespace std;

unordered_map<char, int> countCharacterFrequency(const string& input);

pair<char, int> findMaxFrequencyCharacter(const unordered_map<char, int>& frequency);

#endif 

