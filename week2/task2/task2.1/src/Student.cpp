#include "../include/Student.hpp"

// Конструктор
Student::Student(string n, tm bDate, string grp, int sId, double avgScore)
  : name(n), birthDate(bDate), group(grp), studentId(sId), averageScore(avgScore) {}

// Геттеры
string Student::getName() const {
  return name;
}

tm Student::getBirthDate() const {
  return birthDate;
}

string Student::getGroup() const {
  return group;
}

int Student::getStudentId() const {
  return studentId;
}

double Student::getAverageScore() const {
  return averageScore;
}

// Сеттеры
void Student::setName(const string& n) {
  name = n;
}

void Student::setBirthDate(const tm& bDate) {
  birthDate = bDate;
}

void Student::setGroup(const string& grp) {
  group = grp;
}

void Student::setStudentId(int sId) {
  studentId = sId;
}

void Student::setAverageScore(double avgScore) {
  averageScore = avgScore;
}

// Метод для расчета возраста
int Student::getAge() const {
  time_t now = time(0);
  tm* currentTime = localtime(&now);
  int age = currentTime->tm_year + 1900 - (birthDate.tm_year + 1900);
  return age;
}

// Метод для вывода информации о студенте
string Student::toString() const {
  char buffer[80];
  strftime(buffer, sizeof(buffer), "%Y-%m-%d", &birthDate);
  return "Имя: " + name + "\nДата рождения: " + buffer + "\nГруппа: " + group +
    "\nКод студента: " + to_string(studentId) +
    "\nСредний балл: " + to_string(averageScore);
}

// Метод для проверки, является ли студент отличником
bool Student::isExcellentStudent() const {
  return averageScore >= 4.8;
}
