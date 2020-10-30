#include "book.hpp"


book::book(){
    num_pages = 0;

}

book::book(int n){
    num_pages = n;
}

int book::get_num_pages() const {
    return num_pages;
}