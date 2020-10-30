/******************************************************
** Program: bats.h
** Author: Carlos Gonzalez
** Date: 03/01/2020
** Description: header file for bats class
** Input:
** Output:
******************************************************/
#ifndef BATS_H
#define BATS_H
#include "event.h"
#include "player.h"
#include <iostream>

using namespace std;

class Bats : public Event {
    private:
    public:
        Bats();
        int get_type();
        void percept();
        void encounter(Player*);
        char debug_symbol();
};
#endif