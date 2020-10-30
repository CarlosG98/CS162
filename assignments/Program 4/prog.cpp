/******************************************************
** Program: prog.cpp
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: driver file
** Input:
** Output: runs the game Hunt the Wumpus
******************************************************/

#include "event.h"
#include "wumpus.h"
#include "gold.h"
#include "pit.h"
#include "bats.h"
#include "room.h"
#include "player.h"
#include "game.h"

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

/*****************************************************************************
 * function: check_args
 * description: checks for correct command line arguments. Exits program if arguments are invalid
 * pre-conditions:
 * post-conditions: correct arguments, returns grid size in integer form.
 * **************************************************************************/
int check_args(int ac, char**av){
    int num;
    if(ac != 3){
        cout << "Insuffiencient argument count." << endl;
        exit(EXIT_FAILURE);
    }
    for(int i=0; i < strlen(av[1]); i++){
        if( av[1][i] < 48 || av[1][i] > 57){
            cout << "Grid size must be an integer." << endl;
            exit(EXIT_FAILURE);
        }
        else{
            num = atoi(av[1]);
        }
    }
    if(num < 4){
        cout << "Grid size must be at least 4x4." << endl;
        exit(EXIT_FAILURE);
    }
return num;
}

/*****************************************************************************
 * function: run_debug
 * description: runs the game, but shows events on map
 * pre-conditions: user must enter true as a command line argument
 * post-conditions: runs game with events on map
 * **************************************************************************/
void run_debug(Game& g1){
    bool alive = true, win = false;
    do{
        alive = true; win = false;
        g1.print_debug();
        g1.get_percepts();
        g1.make_move();
        g1.encounters();
        alive = g1.check_life();
        win = g1.check_win();
        
    }while(alive == true && win == false);
}

/*****************************************************************************
 * function: run_normal 
 * description: run the game with events hidden on map
 * pre-conditions: user must enter false as a command line argument
 * post-conditions: running game with hidden elements
 * **************************************************************************/
void run_normal(Game& g1){
    bool alive = true, win = false;
    do{
        g1.print_grid();
        g1.get_percepts();
        g1.make_move();
        g1.encounters();
        alive = g1.check_life();
        win = g1.check_win();
        cout << endl;
    }while(alive == true && win == false);
}

/*****************************************************************************
 * function: check_debug
 * description: retrieves the true/false argument and returns it as a boolean
 * pre-conditions: user must enter true/false as a command line arguement
 * post-conditions: returns boolean
 * **************************************************************************/
bool check_debug(char**av){
    string s;
    bool debug;
    s.append(av[2]);
    if(s == "true"){
        debug = true;
    }
    if(s == "false"){
        debug = false;
    }
return debug;
}

/*****************************************************************************
 * function: main
 * description:
 * pre-conditions:
 * post-conditions:
 * **************************************************************************/
int main(int argc, char** argv){
    srand(time(NULL));
    int restart, grid_size = check_args(argc, argv);
    bool debug_mode = check_debug(argv);
    do{
        Game g1(grid_size);
        g1.fill_grid();
        if(debug_mode == true){
            run_debug(g1);
        }else{
            run_normal(g1);
        }
        cout << endl;
        cout << "Would you like to restart? (0-yes, 1-no): " << endl;
        cin >> restart;
    }while(restart == 0);
return 0;
}