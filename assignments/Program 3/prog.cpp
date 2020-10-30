/******************************************************
** Program: prog.cpp
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: driver file for zootycoon.cpp
** Input:
** Output: runs the game
******************************************************/
#include "animal.h"
#include "zoo.h"
#include "blackbear.h"
#include "tiger.h"
#include "sealion.h"
#include "zootycoon.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time((NULL)));

    Zoo z1;
    bool continue_game = true, bankrupt = false;
    int food_type=0, cont;

    do{
        cout << "MONTH " << z1.get_month() << ": " << endl;
        z1.inc_all_ages();
        print_animals(z1);

        cout << endl;

        bankrupt = check_bank(z1);

        start_event(z1, food_type);

        bankrupt = check_bank(z1);

        monthly_revenue(z1);

        bankrupt = check_bank(z1);

        cout << "BANK AMOUNT: $" << z1.get_bank() << endl;
        purchase(z1);
        cout << "BANK AMOUNT: $" << z1.get_bank() << endl;
        cout << endl;

        bankrupt = check_bank(z1);

        calculate_food_cost(z1, food_type);

        bankrupt = check_bank(z1);

        z1.inc_month();
        get_food_type(&food_type);

        if(bankrupt == false){
            cout << "Would you like to continue game? (1 yes, 0 no): ";
            cin >> cont;
            cout << endl;
        }else{cout << "Your zoo went bankrupt! Shutting down..." << endl; return 0;}
        if(cont == 1){
            continue_game = true;
        }else{
            continue_game = false;
        }
    }while(continue_game == true && bankrupt == false);
return 0;
}