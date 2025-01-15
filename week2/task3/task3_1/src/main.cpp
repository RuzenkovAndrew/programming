#include <iostream>
#include "../include/Author.hpp"
#include "../include/Book.hpp"

using namespace std;

int main() {
  // Пример использования
  Author author("Лев Толстой", 1828);
  Book book(author);

  cout << "Автор: " << book.getAuthor().getName() << endl;
  cout << "Год рождения: " << book.getAuthor().getBirthYear() << endl;

  return 0;
}

