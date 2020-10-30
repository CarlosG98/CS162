/******************************************************
** Program: room.cpp
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: function definitions for room class
** Input:
** Output:
******************************************************/
#include "room.h"
#include <iostream>

using namespace std;

Room::Room(){
    this->room_event = NULL;
}

/*****************************************************************************
 * function: get_event
 * description: returns the type of event a room points to
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
int Room::get_event(){
    if(room_event != NULL){
        return room_event->get_type();
    }else{
        return -1;
    }
}

void Room::debug_symbol(){
    cout << room_event->debug_symbol(); //returns the event's affiliated char symbol
}

void Room::set_room(Event* e){
    this->room_event = e; 
}

void Room::get_percept(){
    room_event->percept();
}

void Room::get_encounter(Player* player){
    room_event->encounter(player);
}