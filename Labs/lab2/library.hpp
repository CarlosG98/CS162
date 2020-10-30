#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.hpp"

class library{
private:
    int num_books;
    book* book;
public:
    int get_num_books() const;
    book * const get_books(int)
}