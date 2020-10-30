#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <string>
#include "card.hpp"
#include "deck.hpp"
 
using namespace std;

class Hand {
    private: 
        Card* cards;
        int n_cards; // number of cards in hand
    public:
        Hand();
        ~Hand();
        Hand(const Hand&);
        Hand& operator= (const Hand&);
        int get_n_cards();
        void start_hand(Card, int);
        void set_hands_cards(int);
        void show_hand();
        Card play_card(int);
        void shrink_hand(int);
        void grow_hand(Card&);
        bool check_hand(Card, int);
        bool check_eights(); //checks if hand has a card of rank 8
        int get_eights(); //gets card of rank 8
};

#endif 