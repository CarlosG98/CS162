#include <iostream>
#include "deck.hpp"
#include "card.hpp"
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std; 

Deck::Deck(){
    n_cards = 52;
}


void Deck::create_deck(){
    int y = 0; //counter variable for rank
    for(int i=0; i < 52; i++){
        if(y==13){ //if y exceeds max rank of 12
            y = 0; //reset rank back to 0
        }
        cards[i].set_rank(y); //set rank to current value for y
        cards[i].set_srank(y); //sets string rank to y
        if(i < 13){
            cards[i].set_suit(0); // 0 is for clubs
            cards[i].set_ssuit(0);
        }
        if(i >= 13 && i < 26){
            cards[i].set_suit(1); // 1 is for diamonds
            cards[i].set_ssuit(1);
        }
        if(i >= 26 && i < 39){
            cards[i].set_suit(2); // 2 is for hearts
            cards[i].set_ssuit(2);
        }
        if(i >= 39 && i < 52){
            cards[i].set_suit(3); // 3 is for spades
            cards[i].set_ssuit(3);
        }
        y++;
    }
}

void Deck::shuffle(){

    int rn;
    for(int i = 0; i < 52; i++){
        rn = rand() % 52;
        Card temp_card = cards[i];
        cards[i] = cards[rn];
        cards[rn] = temp_card;
    }
}

void Deck::print_deck(){
    	for(int i=0; i < 13; i++){
		cout <<  cards[i].get_suit() << cards[i].get_rank() << " ";
	}

	cout << endl;
	
	for(int i=13; i<26; i++){
		cout << cards[i].get_suit() << cards[i].get_rank() << " ";
	}

	cout << endl;
	
	for(int i=26; i < 39; i++){
		cout << cards[i].get_suit() << cards[i].get_rank() << " ";
	}

	cout << endl;

	for(int i=39; i < 52; i++){
		cout << cards[i].get_suit() << cards[i].get_rank() << " ";
	}
	cout << endl;	
}

void Deck::remove_card(){
    --n_cards;
}

int Deck::get_n_cards(){
    return n_cards;
}

Card Deck::deal_card(){
    int a = n_cards-1;
    remove_card();
    return cards[a];
}

void Deck::show_top_card(){
    cout << cards[n_cards-1].get_srank() << " of "<< cards[n_cards-1].get_ssuit() << endl;
}

void Deck::set_stock(){
    n_cards = 0;
}

Card Deck::take_from(){
    return cards[n_cards];
}

Card Deck::get_top_card(){
    return cards[n_cards-1];
}

void Deck::add_card(Card c1, int index){
    cards[index] = c1;
    n_cards++;
}