// Функция для вычисления количества дней в месяце
int getDaysInMonth(int year, int month) 
{
    if (month == 2) 
    { // Февраль
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) 
        {
            return 29;
        } 
        else 
        {
            return 28;
        }
    } 
    else if (month == 4 || month == 6 || month == 9 || month == 11) 
    { // Месяцы с 30 днями
        return 30;
    } 
    else // Остальные месяцы (с 31 днем)
    { 
        return 31;
    }
}

