#include <iostream>
#include "../include/Student.hpp"

using namespace std;

int main() {
  // Создание объектов класса Student
  tm birthDate1 = {};
  birthDate1.tm_year = 2005 - 1900; // Год (с 1900)
  birthDate1.tm_mon = 7 - 1; // Месяц (с 0)
  birthDate1.tm_mday = 4; // День

  Student student1("Андрей Рыженков", birthDate1, "23ИБ1б", 12345, 4.9);

  tm birthDate2 = {};
  birthDate2.tm_year = 2002 - 1900;
  birthDate2.tm_mon = 10 - 1;
  birthDate2.tm_mday = 20;

  Student student2("Макс Ващенко", birthDate2, "Группа 2", 54321, 4.5);

  // Тестирование методов
  cout << student1.toString() << endl;
  cout << "Возраст: " << student1.getAge() << " лет" << endl;
  cout << "Отличник: " << (student1.isExcellentStudent() ? "Да" : "Нет") << endl;

  cout << endl;

  cout << student2.toString() << endl;
  cout << "Возраст: " << student2.getAge() << " лет" << endl;
  cout << "Отличник: " << (student2.isExcellentStudent() ? "Да" : "Нет") << endl;

  return 0;
}
