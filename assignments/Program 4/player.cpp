/******************************************************
** Program: player.cpp
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: function definitions for player class
** Input:
** Output:
******************************************************/
#include "player.h"
#include <iostream>

using namespace std;

/*****************************************************************************
 * function: Player
 * description: player constructor
 * pre-conditions: random x position, y position, and grid size
 * post-conditions:
 * **************************************************************************/
Player::Player(int x, int y, int size){
    start_x = x;
    start_y = y;
    current_x = start_x;
    current_y = start_y;
    grid = size;
    alive = true;
    has_gold = false;
    arrows = 3;
}

int Player::get_startx(){
    return start_x;
}

int Player::get_starty(){
    return start_y;
}

int Player::get_currentx(){
    return current_x;
}

int Player::get_currenty(){
    return current_y;
}

bool Player::check_life(){
    return alive;
}

bool Player::check_gold(){
    return has_gold;
}

int Player::get_arrows(){
    return arrows;
}

/*****************************************************************************
 * function: move_player
 * description: move player based on input
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
void Player::move_player(char direction){
    if(direction == 'w' || direction == 'W'){
        current_y -= 1; //up
    }
    if(direction == 's' || direction == 'S'){
        current_y += 1; //down
    }
    if(direction == 'd' || direction == 'D'){
        current_x += 1; //right
    }
    if(direction == 'a' || direction == 'A'){
        current_x -=1; //left
    }
}

void Player::set_alive(bool a){
    alive = a;
}

void Player::set_has_gold(bool g){
    has_gold = g;
}

void Player::remove_arrow(){
    --arrows;
}

/*****************************************************************************
 * function: bats_move
 * description: bats randomly move player to new location
 * pre-conditions:
 * post-conditions: new player location on grid
 * **************************************************************************/
void Player::bats_move(){
    int xp, yp;
    do{
        xp = rand() % grid;
        yp = rand() % grid;
    }while(xp == current_x && yp == current_y); // we want bats to actually move the player  

    current_x = xp;
    current_y = yp;
}



