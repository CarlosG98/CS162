/******************************************************
** Program: pit.h
** Author: Carlos Gonzalez
** Date: 03/01/2020
** Description: header file for pit class
** Input:
** Output:
******************************************************/
#ifndef PIT_H
#define PIT_H
#include "event.h"
#include <iostream>

using namespace std;

class Pit : public Event {
    private:
    public:
        Pit();
        int get_type();
        void percept();
        void encounter(Player*);
        char debug_symbol();
};

#endif