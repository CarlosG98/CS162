/******************************************************
** Program: wumpus.h
** Author: Carlos Gonzalez
** Date: 03/01/2020
** Description: header file for wumpus class
** Input:
** Output:
******************************************************/
#ifndef WUMPUS_H
#define WUMPUS_H
#include "event.h"
#include <iostream>

using namespace std;

class Wumpus : public Event {
    private:
    public:
        Wumpus();
        int get_type();
        void percept();
        void encounter(Player*);
        char debug_symbol();
};
#endif