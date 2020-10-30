#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include "deck.hpp"
#include "player.hpp"

using namespace std;

class Game {
  private:
    Deck cards;
    Deck stock;
    Player players[2];
  public:
  Game();
  Game(string);
  void create_deck();
  void shuffle_deck();
  void print_deck();
  string get_player_name(int);
  void distribute_cards();
  void show_player_hand(int);
  void show_top_card();
  void add_to_stock();
  void set_stock();
  Card take_from();
  int get_stock_n_cards();
  void pass_card(int, int);
  void shrink_hand(int, int);
  void grow_hand(int);
  Card get_player_card(int, int);
  Card get_top_card();
  bool check_hand(Card, int, int);
  bool check_eights(int);
  int get_eights(int);
  int get_hand_n_cards(int);



  // must have constructors, destructor, accessor methods, and mutator methods
};

#endif
