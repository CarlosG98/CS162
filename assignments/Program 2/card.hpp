#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>
using namespace std;

class Card {
    private:
        int rank; //range 0-12
        int suit; //range 0-3
        string srank;
        string ssuit;
    public:
        int get_rank();
        int get_suit();
        string get_srank();
        string get_ssuit();
        void set_rank(int);
        void set_suit(int);
        void set_srank(int);
        void set_ssuit(int);

};

#endif