// Функция для нахождения максимального элемента и его количества
void max_element(int numbers[], int size, int &maxElement, int &count) 
{
    maxElement = numbers[0]; // Предполагаем, что первый элемент - максимальный
    count = 1; // Количество максимальных элементов, включая первый

    for (int i = 1; i < size; i++) {
    
        if (numbers[i] > maxElement) 
        {
            maxElement = numbers[i];
            count = 1; // Сбрасываем счетчик, так как найден новый максимальный
        } 
        else if (numbers[i] == maxElement) 
        {
            count++; // Увеличиваем счетчик, если найден элемент, равный максимальному
        }
    }
}

