#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include "cards.hpp"

using namespace std;

class deck{
private:
	card deck[52];
public: 
	void create_deck();
	void swap_cards(card* , int, int);
	void shuffle();
	void print_deck();
};
#endif
