#ifndef PASSWORD_CRACKER_HPP
#define PASSWORD_CRACKER_HPP

#include <iostream>
#include <iomanip>
#include <openssl/md5.h>
#include <sstream>
#include <string>
#include <vector>
#include <spdlog/spdlog.h>
#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

extern const string password;
extern unsigned char targetMD5[MD5_DIGEST_LENGTH];

void computeMD5FromString(const string &str, unsigned char *result);
string md5ToString(unsigned char *md);
void bruteForceMD5Thread(int threadId, const string &targetMD5, const string &chars, int len, long long startIdx, long long endIdx);
void bruteForceMD5(const string &targetMD5, int numThreads);

#endif // PASSWORD_CRACKER_HPP
