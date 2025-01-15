#include "../include/ArrayStack.h"
#include <iostream>
#include <limits>
#include <string>

void fillIntStack(ArrayStack<int>& stack) {
    int num;
    std::string input;
    std::cout << "Введите целые числа (для завершения нажмите Enter):" << std::endl;
    while (true) {
        std::cout << "Число: ";
        std::getline(std::cin, input);
          if (input.empty())
             break;

         try {
              num = std::stoi(input);
              stack.push(num);
        } catch (const std::invalid_argument& e) {
            std::cout << "Некорректный ввод, попробуйте ещё раз" << std::endl;
         }
    }
}

void fillStringStack(ArrayStack<std::string>& stack) {
    std::string text;
    std::cout << "Введите строки (для завершения нажмите Enter):" << std::endl;
    while (true) {
         std::cout << "Строка: ";
        std::getline(std::cin, text);
         if (text.empty())
            break;

        stack.push(text);
    }
}


template <typename T>
void printStack(ArrayStack<T>& stack, const std::string& message) {
    std::cout << message << std::endl;
    try {
        if (stack.isEmpty()) {
            std::cout << "Стек пуст!" << std::endl;
        } else {
            while (!stack.isEmpty()) {
                std::cout << stack.pop() << std::endl;
            }
        }
    } catch (const std::out_of_range& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    ArrayStack<int> intStack;
    fillIntStack(intStack);
    printStack(intStack, "Стек целых чисел (сверху вниз):");

    ArrayStack<std::string> stringStack;
    fillStringStack(stringStack);
    printStack(stringStack, "Стек строк (сверху вниз):");

    return 0;
}
