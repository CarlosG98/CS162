#ifndef BOOK_H
#define BOOK_H

class book{
private: 
    int num_pages;
    //int num_chapters;
    //string title;
    //string author;
public:
    //constructors
    book();
    book(int);

    int get_num_pages() const; //function cannot change private variables if using const
    void set_num_pages(int);

};