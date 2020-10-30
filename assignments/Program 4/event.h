/******************************************************
** Program: event.h
** Author: Carlos Gonzalez
** Date: 03/01/2020
** Description: header file for event class
** Input:
** Output:
******************************************************/
#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include "player.h"

using namespace std;

class Event{
    protected:
        int type;
    private:
    public:
        Event(int);
        virtual void percept() = 0;
        virtual void encounter(Player*) = 0;
        virtual int get_type() =0;
        virtual char debug_symbol() =0;
};
#endif