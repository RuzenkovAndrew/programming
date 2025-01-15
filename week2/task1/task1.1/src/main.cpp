#include <iostream>
#include "../include/people.hpp"

int main() {
  // Создание экземпляров класса
  people people1("Андрей", 22);
  people people2("Кирилл", 31);
  people people3; // Пользователь с использованием конструктора по умолчанию

  // Вывод информации о каждом пользователе
  std::cout << "Пользователь 1: " << people1.getName() << ", Возраст: " << people1.getAge() <<" лет" << std::endl;
  std::cout << "Пользователь 2: " << people2.getName() << ", Возраст: " << people2.getAge() << " лет" << std::endl;
  std::cout << "Пользователь 3: " << people3.getName() << ", Возраст: " << people3.getAge() << " лет" << std::endl;

return 0;
}
