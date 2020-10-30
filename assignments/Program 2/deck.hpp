#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <string>
#include "card.hpp"

using namespace std;

class Deck {
  private:
    Card cards[52];
    int n_cards;  // Number of cards remaining in the deck.
  public:
    Deck();
    void create_deck();
    void shuffle();
    void print_deck();
    void remove_card();
    int get_n_cards();
    Card deal_card();
    void show_top_card();
    void set_stock();
    Card take_from(); //for drawing card from deck
    Card get_top_card(); //for comparing top card of pile
    void add_card(Card, int);
};

#endif