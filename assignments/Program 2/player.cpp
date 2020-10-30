#include <iostream>
#include <string>
#include "player.hpp"
#include "hand.h"
#include "card.hpp"
#include "deck.hpp"

Player::Player(){
    Hand hand;
    name = "Computer" ;
}

Player::Player(string username){
    Hand hand;
    name = username;
}

string Player::get_name(){
    return name;
}

Hand Player::get_hand(){

    return hand;
}

void Player::deal_hand(Card c1, int index){
    hand.start_hand(c1, index);
}

void Player::show_hand(){
    hand.show_hand();
    cout << endl;
}

Card Player::play_card(int index){
    return hand.play_card(index);
}

void Player::shrink_hand(int index){
    hand.shrink_hand(index);
}

void Player::grow_hand(Card& c1){
    hand.grow_hand(c1);
}

bool Player::check_hand(Card c1, int suit){
    return hand.check_hand(c1, suit);
}

bool Player::check_eights(){
    return hand.check_eights();
}

int Player::get_eights(){
    return hand.get_eights();
}

int Player::get_n_cards(){
    return hand.get_n_cards();
}