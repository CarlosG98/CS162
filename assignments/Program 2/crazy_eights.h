/****************************************************************************************************
 * Program: crazy_eights
 * Author: Carlos Gonzalez
 * Date: January 2020
 * Description: header file for crazy_eights.cpp
 * Input:
 * Output:
 * ************************************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "game.hpp"
#include "card.hpp"
#include "deck.hpp"
#include "hand.h"
#include "player.hpp"

using namespace std;

void start_deck(Game&);
string get_players_name();
bool check_card(Game&, int, int);
bool check_card_pt2(Game&, int, int, int);
int get_valid_card(bool &, Game&);
int get_valid_card_computer(bool &, Game&, int);
void draw_card(Game&, int);
void draw_card_pt2(Game&, int, int);
bool check_eights(Game&);
void player_first_turn_part2(Game &);
int player_first_turn(Game&);
bool check_com_eights(Game&);
int get_valid_card_com(bool&, Game&, int);
void print_coms_suit(int);
int computers_turn(Game&, int);
int get_valid_card_pt2(bool &, Game&, int);
void player_next_turn_part2(Game &, int);
int player_next_turn(Game&, int);
void update_num(int*, int*);