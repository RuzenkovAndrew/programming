#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include <string>

class people {
private:
  std::string name;
  int age;

public:
  // Конструктор по умолчанию
  people();

  // Конструктор с параметрами
  people(std::string name, int age);

  // Геттеры и сеттеры
  std::string getName();
  void setName(std::string name);
  int getAge();
  void setAge(int age);
};

#endif // people_HPP
