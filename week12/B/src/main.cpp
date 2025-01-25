#include <iostream>
#include <string>
#include <chrono>
#include <spdlog/spdlog.h>
#include "password_cracker.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <threads>" << endl;
        return 1;
    }

    int numThreads = 0;
    string threadsArg = argv[1];

    size_t pos = threadsArg.find("threads==");
    if (pos != string::npos) {
        try {
            numThreads = stoi(threadsArg.substr(pos + 9));
        } catch (const std::invalid_argument &e) {
            cerr << "Invalid number of threads!" << endl;
            return 1;
        }
    } else {
        cerr << "Usage: " << argv[0] << " <threads==number>" << endl;
        return 1;
    }

    if (numThreads <= 0) {
        cerr << "Invalid number of threads!" << endl;
        return 1;
    }

    auto startTime = chrono::high_resolution_clock::now();
    computeMD5FromString(password, targetMD5);
    string targetMD5String = md5ToString(targetMD5);

    spdlog::info("Starting brute force for MD5: {}", targetMD5String);
    bruteForceMD5(targetMD5String, numThreads);

    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = endTime - startTime;

    spdlog::info("Total execution time: {} seconds", duration.count());

    return 0;
}
