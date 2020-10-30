#include <iostream>
#include <string>

#include "game.hpp"
#include "player.hpp"
#include "hand.h"
#include "deck.hpp"
#include "card.hpp"

using namespace std;

Game::Game(){
    players[0] = Player();
    players[1] = Player();
}

Game::Game(string username){
    players[0] = Player();
    players[1] = Player(username);
}

void Game::create_deck(){
    cards.create_deck();
}

void Game::shuffle_deck(){
    cards.shuffle();
}

void Game::print_deck(){
    cards.print_deck();
}

string Game::get_player_name(int num){
    return players[num].get_name();
}

void Game::show_top_card(){
    stock.show_top_card();
}

void Game::distribute_cards(){
    Card c;
    for(int i=0; i < 7 ; i++){
        c = cards.deal_card();
        players[0].deal_hand(c, i);
    }
    for(int i=0; i < 7; i++){
        c = cards.deal_card();
        players[1].deal_hand(c, i);
    }
    cards.remove_card();
}

void Game::show_player_hand(int playr){
    players[playr].show_hand();
}

void Game::set_stock(){
    stock.set_stock();
}

int Game::get_stock_n_cards(){
    return stock.get_n_cards();
}

Card Game::take_from(){
   return cards.take_from();
}

void Game::add_to_stock(){
    int a = stock.get_n_cards();
    Card c1 = cards.take_from();
    stock.add_card(c1, a);
    cards.remove_card();
}

void Game::pass_card(int plyr, int index){
    Card c1 = players[plyr].play_card(index); //index modded before passing to param
    stock.add_card(c1, stock.get_n_cards());
}

void Game::shrink_hand(int plyr, int card){
    players[plyr].shrink_hand(card);
}

void Game::grow_hand(int plyr){
    Card c1 = cards.take_from();
    cards.remove_card();
    players[plyr].grow_hand(c1);
}

Card Game::get_player_card(int plyr, int index){
    return players[plyr].play_card(index);
}

Card Game::get_top_card(){
    return stock.get_top_card();
}

bool Game::check_hand(Card c1, int plyr, int suit){
    return players[plyr].check_hand(c1, suit);
}

bool Game::check_eights(int plyr){
    return players[plyr].check_eights();
}

int Game::get_eights(int plyr){
    return players[plyr].get_eights();
}

int Game::get_hand_n_cards(int plyr){
    return players[plyr].get_n_cards();
}