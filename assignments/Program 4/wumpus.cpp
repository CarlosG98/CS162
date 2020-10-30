/******************************************************
** Program: wumpus.cpp
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: function definitions for wumpus class
** Input:
** Output:
******************************************************/
#include "wumpus.h"
#include <iostream>

using namespace std;

Wumpus::Wumpus() : Event(4) {
    type = 4;
}

int Wumpus::get_type(){
    return type;
}

void Wumpus::percept(){
    cout << "You smell a terrible stench." << endl;
}

void Wumpus::encounter(Player* player){
    player->set_alive(false);
    cout << "Wumpus thanks you for the meal." << endl;
}

char Wumpus::debug_symbol(){
    return 'W';
}