/******************************************************
** Program: player.h
** Author: Carlos Gonzalez
** Date: 03/01/2020
** Description: header file for player class
** Input:
** Output:
******************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

class Player {
    private:
        int start_x;
        int start_y;
        int current_x;
        int current_y;
        int grid;
        bool alive;
        bool has_gold;
        int arrows;
    public:
        Player(int, int, int);
        int get_startx();
        int get_starty();
        int get_currentx();
        int get_currenty();
        bool check_life();
        bool check_gold();
        int get_arrows();
        void move_player(char);
        void set_alive(bool);
        void set_has_gold(bool);
        void bats_move();
        void remove_arrow();
};

#endif