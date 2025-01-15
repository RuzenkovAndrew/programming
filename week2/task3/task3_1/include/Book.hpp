#ifndef BOOK_HPP
#define BOOK_HPP

#include "Author.hpp"

class Book {
private:
    Author author;

public:
    // Конструктор
    Book(const Author& author);

    // Метод для получения информации об авторе
    Author getAuthor() const;

    // Метод для установки нового автора
    void setAuthor(const Author& author);
};

#endif // BOOK_HPP
