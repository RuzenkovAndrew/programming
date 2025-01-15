#include "../include/email_validator.hpp"
#include <regex>

bool isValidEmail(const std::string& email) {
    // Регулярное выражение для проверки адреса электронной почты
    const std::regex emailPattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return std::regex_match(email, emailPattern);
}

