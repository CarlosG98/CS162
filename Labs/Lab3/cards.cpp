#include <iostream>
#include "cards.hpp"

using namespace std; 

char card::get_suit() const {
	return suit;
}

int card::get_rank() const {
	return rank;
}

void card::set_suit(char new_suit){
	suit = new_suit;
}

void card::set_rank(int new_rank){
	rank = new_rank;
}

