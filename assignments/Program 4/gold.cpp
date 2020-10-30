/******************************************************
** Program: gold.cpp
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: function definitions for gold class
** Input:
** Output:
******************************************************/
#include "gold.h"
#include <iostream>

using namespace std;

Gold::Gold() : Event(1) {
    type = 1;
}

int Gold::get_type(){
    return type;
}

void Gold::percept(){
    cout << "You see a glimmer nearby." << endl;
}

void Gold::encounter(Player* player){
    cout << "Gold collected!" << endl;
    player->set_has_gold(true);
}

char Gold::debug_symbol(){
    return 'G';
}