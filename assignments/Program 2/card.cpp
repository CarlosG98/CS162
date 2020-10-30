#include <iostream>
#include <string>
#include <sstream>
#include "card.hpp"

using namespace std;

int Card::get_rank(){
    return rank;
}

int Card::get_suit(){
    return suit;
}

string Card::get_srank(){
    return srank;
}

string Card::get_ssuit(){
    return ssuit;
}

void Card::set_suit(int a){
    suit = a;
}

void Card::set_rank(int b){
    rank = b;
}

void Card::set_srank(int a){

    if( a >= 1 || a <= 9){
            stringstream ss;
            ss << a;
            ss >> srank;
    }
    if(a == 0){
        srank = "Ace";
    }
    if(a == 10){
        srank = "Jack";
    }
    if(a == 11){
        srank = "Queen";
    }
    if(a == 12){
        srank = "King";
    }
}

void Card::set_ssuit(int a){
    if(a == 0){
        ssuit = "Clubs";
    }
    if(a == 1){
        ssuit = "Diamonds";
    }
    if(a == 2){
        ssuit = "Hearts";
    }
    if(a == 3){
        ssuit = "Spades";
    }
}