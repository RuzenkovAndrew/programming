void pyramid(int height) 
{
    for (int i = 1; i <= height; i++) 
    {
        // Вывод пробелов перед первой пирамидой
        for (int j = 1; j <= height - i; j++) 
        {
            std::cout << " ";
        }

        // Вывод первой пирамиды
        for (int j = 1; j <= i; j++) 
        {
            std::cout << "#";
        }

        std::cout << " "; // Пробел между пирамидами

        // Вывод второй пирамиды
        for (int j = 1; j <= i; j++) 
        {
            std::cout << "#";
        }

        std::cout << std::endl; // Переход на новую строку
    }
}

