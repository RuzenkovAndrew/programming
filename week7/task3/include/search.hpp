#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <string>
#include <vector>

using namespace std;

class FileSearcher {
public:
    static vector<string> searchByName(const string& directory, const string& filename);
    static vector<string> searchByContent(const string& directory, const string& keyword);
};

#endif 

