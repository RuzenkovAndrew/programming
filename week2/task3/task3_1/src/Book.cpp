#include "../include/Book.hpp"

// Реализация методов класса Book
Book::Book(const Author& author) : author(author) {}

Author Book::getAuthor() const {
  return author;
}

void Book::setAuthor(const Author& author) {
  this->author = author;
}

