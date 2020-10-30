/*************************************************************************************************************
 * Program: Crazy Eights
 * Author: Carlos Gonzalez
 * Date: January 27, 2020
 * Description: a human vs computer card game
 * Inputs: 
 * Outputs:
 * *********************************************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "game.hpp"
#include "card.hpp"
#include "deck.hpp"
#include "hand.h"
#include "player.hpp"
#include "crazy_eights.h"


using namespace std;

int main(){

    srand(time(NULL));
    string username = get_players_name();
    Game g1 = Game(username);
    cout << "Hello, " << g1.get_player_name(1) << "!" << endl;
    start_deck(g1);
    cout << endl;
    
    cout << "TOP CARD: " ; g1.show_top_card();

    int players_num, computer_num, a, b;
    players_num = player_first_turn(g1);
    a = players_num;

    for(int i=0; i < 37; i++){
        cout << "TOP CARD: "; g1.show_top_card();
        if(i % 2 == 0){
            cout << "COMPUTER IS MAKING THEIR MOVE..." << endl;
            cout << endl;
            computer_num = computers_turn(g1, a);
            update_num(&b, &computer_num);
        
        }
        if(i%2 == 1){
            g1.show_player_hand(1);
            players_num = player_next_turn(g1, b);
            update_num(&a, &players_num);
        }
    }

return 0;
}

