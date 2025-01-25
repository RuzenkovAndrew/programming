#include "password_cracker.hpp"
#include <openssl/md5.h>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <spdlog/spdlog.h>
#include <chrono>
#include <atomic>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

atomic<bool> found(false);

void computeMD5FromString(const string &str, unsigned char *result) {
    MD5((unsigned char *)str.c_str(), str.length(), result);
}

string md5ToString(unsigned char *md) {
    stringstream ss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)md[i];
    }
    return ss.str();
}

void bruteForceMD5Thread(int threadId, const string &targetMD5, const string &chars, int len, long long startIdx, long long endIdx) {
    unsigned char result[MD5_DIGEST_LENGTH];

    for (long long index = startIdx; index < endIdx; ++index) {
        if (found.load()) break;

        string currentStr;
        long long tempIndex = index;
        for (int i = 0; i < len; i++) {
            currentStr = chars[tempIndex % chars.size()] + currentStr;
            tempIndex /= chars.size();
        }

        computeMD5FromString(currentStr, result);
        string computedMD5 = md5ToString(result);

        if (computedMD5 == targetMD5) {
            found.store(true);
            spdlog::info("Thread {}: Found password: {}", threadId, currentStr);
            return;
        }
    }
}

void bruteForceMD5(const string &targetMD5, int numThreads, const string &password) {
    const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int len = password.length();
    long long totalCombinationsCount = pow(chars.size(), len);

    vector<thread> threads;
    long long range = totalCombinationsCount / numThreads;
    for (int i = 0; i < numThreads; ++i) {
        long long startIdx = i * range;
        long long endIdx = (i == numThreads - 1) ? totalCombinationsCount : (i + 1) * range;
        threads.push_back(thread(bruteForceMD5Thread, i, ref(targetMD5), ref(chars), len, startIdx, endIdx));
    }

    for (auto &t : threads) {
        t.join();
    }
}

