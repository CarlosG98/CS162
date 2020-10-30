#include <iostream>
#include "deck.hpp"
#include <ctime>
#include <cstdlib>

using namespace std;



void deck::create_deck(){
	
int y=1; //counter variable for card rank

	for(int i=0; i < 52; i++){

		if(y == 14){ //if pass max rank
			y = 1; // reset to starting rank
		}

		deck[i].set_rank(y); 

		if(i < 13){
			deck[i].set_suit('D'); //first 13 cards get Diamond rank
		}
		if(i>=13 && i<26){
			deck[i].set_suit('C'); //Next 13 get Club rank
		}
		if(i>=26 && i < 38){
			deck[i].set_suit('H'); //Next 13 get Hearts rank
		}
		if(i>=38){
			deck[i].set_suit('S'); //Last 13 get Spades rank
		}
		y++; //increment y (card rank) after each loop
	}
}

void deck::swap_cards(card *deck, int x, int rand_num){
	
	card temp_card = deck[x];
	deck[x] = deck[rand_num];
	deck[rand_num] = temp_card;
}
	

void deck::shuffle(){
	
	int rand_num;

	for(int i=0; i < 52; i++){ //each card will get swapped
		rand_num = rand() % 52; //generates random card in deck that will swap with card at i
		swap_cards(deck, i, rand_num);
	} 
	
}
void deck::print_deck(){
	for(int i=0; i < 13; i++){
		cout <<  deck[i].get_suit() << deck[i].get_rank() << " ";
	}

	cout << endl;
	
	for(int i=13; i<26; i++){
		cout << deck[i].get_suit() << deck[i].get_rank() << " ";
	}

	cout << endl;
	
	for(int i=26; i < 39; i++){
		cout << deck[i].get_suit() << deck[i].get_rank() << " ";
	}

	cout << endl;

	for(int i=39; i < 52; i++){
		cout << deck[i].get_suit() << deck[i].get_rank() << " ";
	}
	cout << endl;	
}

