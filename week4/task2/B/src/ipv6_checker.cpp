#include "../include/ipv6_checker.hpp"
#include <regex>

// Функция для проверки правильности адреса IPv6
bool isValidIPv6(const std::string& ip) {
    // Регулярное выражение для полной формы IPv6
    std::regex ipv6Pattern(R"(^([0-9a-fA-F]{4}:){7}([0-9a-fA-F]{4})$)");
    return std::regex_match(ip, ipv6Pattern);
}


