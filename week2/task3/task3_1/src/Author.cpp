#include "../include/Author.hpp"

// Реализация методов класса Author
Author::Author(const string& name, int birthYear)
  : name(name), birthYear(birthYear) {}

string Author::getName() const {
  return name;
}

void Author::setName(const string& name) {
  this->name = name;
}

int Author::getBirthYear() const {
  return birthYear;
}

void Author::setBirthYear(int birthYear) {
  this->birthYear = birthYear;
}
