/******************************************************
** Program: pit.cpp
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: function definitions for pit class
** Input:
** Output:
******************************************************/
#include "pit.h"
#include <iostream> 

using namespace std;

Pit::Pit() : Event(2) {
    type = 2;
}

int Pit::get_type(){
    return type;
}

void Pit::percept(){
    cout << "You feel a breeze." << endl;
}

void Pit::encounter(Player* player){
    player->set_alive(false);
    cout << "You have fallen into the pit. Farewell." << endl;
}

char Pit::debug_symbol(){
    return 'P'; 
}

