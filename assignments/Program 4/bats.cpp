/******************************************************
** Program: bats.cpp
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: function definitions for bats.h
** Input:
** Output:
******************************************************/
#include "bats.h"
#include <iostream>

using namespace std;

Bats::Bats() : Event(3){
    type = 3; 
}

int Bats::get_type(){
    return type;
}

void Bats::percept(){
    cout << "You hear wings flapping." << endl;
}

void Bats::encounter(Player* player){
   cout << "An angry bat has grabbed you! Where are they taking you?" << endl;
}

char Bats::debug_symbol(){
    return 'B';
}