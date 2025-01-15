#include "../include/date.h"

time_t date(int year, int month, int day) {
    tm dateInfo = {}; // Инициализация структуры tm
    dateInfo.tm_year = year - 1900; // Год с 1900
    dateInfo.tm_mon = month - 1;     // Месяц (0 - январь)
    dateInfo.tm_mday = day;          // День месяца

    return mktime(&dateInfo); // Преобразуем в time_t
}

