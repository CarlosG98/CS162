/******************************************************
** Program: gold.h
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: header file for gold class
** Input:
** Output:
******************************************************/
#ifndef GOLD_H
#define GOLD_H
#include "event.h"
#include <iostream>

using namespace std;

class Gold : public Event {
    private:
    public:
        Gold();
        int get_type();
        void percept();
        void encounter(Player*);
        char debug_symbol();
};

#endif