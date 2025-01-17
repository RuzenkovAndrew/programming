#include "../include/memory.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <fstream>
#include <sstream>
#endif

long long getSystemMemory() {
#ifdef _WIN32
    MEMORYSTATUSEX memStatus;
    memStatus.dwLength = sizeof(memStatus);
    if (GlobalMemoryStatusEx(&memStatus)) {
        return memStatus.ullTotalPhys;
    }
#else
    std::ifstream meminfo("/proc/meminfo");
    if (meminfo.is_open()) {
        long long totalMem = 0;

        std::string line;
        while (std::getline(meminfo, line)) {
            if (line.rfind("MemTotal:", 0) == 0) {
                std::stringstream ss(line);
                std::string label;
                ss >> label >> totalMem;
                meminfo.close();
                return totalMem * 1024; //convert kb to bytes
            }
        }

        meminfo.close();

    }
#endif
    return 0; // Возвращаем 0 в случае ошибки
}
