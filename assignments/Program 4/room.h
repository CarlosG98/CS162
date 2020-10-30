/******************************************************
** Program: room.h
** Author: Carlos Gonzalez
** Date: 03/01/2020
** Description: header file for room class
** Input:
** Output:
******************************************************/
#ifndef ROOM_H
#define ROOM_H

#include "event.h"
#include <iostream>

using namespace std;

class Room{
    private:
        Event* room_event;
        int room_x;
        int room_y;
    public: 
        Room();
        int get_event();
        void debug_symbol();
        void set_room(Event*);
        void get_percept();
        void get_encounter(Player*);
};
#endif