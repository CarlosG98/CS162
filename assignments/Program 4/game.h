/******************************************************
** Program: game.h
** Author: Carlos Gonzalez
** Date: 03/01/2020
** Description: header file for game class
** Input:
** Output:
******************************************************/
#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "event.h"
#include "gold.h"
#include "pit.h"
#include "room.h"
#include "wumpus.h"
#include "bats.h"

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Game {
    private:
        Player* player;
        int grid_size;
        bool wumpus_alive;
        Gold* g;
        Pit* p;
        Bats* b;
        Wumpus* wump;
        vector<vector<Room>> grid;
    public:
        Game(int);
        ~Game();
        void print_grid();
        void print_debug();
        void place_events(int);
        void fill_grid();
        void awake_wumpus();
        int check_for_event(int, int);
        void get_percept(int, int);
        void shoot_arrow(char);
        void shoot_arrow_north();
        void shoot_arrow_south();
        void shoot_arrow_west();
        void shoot_arrow_east();
        void kill_wump();
        void encounters();
        void get_percepts();
        void make_move();
        void move_player(char);
        bool check_win();
        bool check_life();
        bool check_move(char);
};

#endif