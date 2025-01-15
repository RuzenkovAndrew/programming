#include "../include/people.hpp"

// Реализация методов
std::string people::getName() {
  return name;
}

void people::setName(std::string name) {
  this->name = name;
}

int people::getAge() {
  return age;
}

void people::setAge(int age) {
  this->age = age;
}

people::people() : name("Unknown"), age(0) {}

people::people(std::string name, int age) {
  this->name = name;
  this->age = age;
}

