#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include "hand.h"

using namespace std;

class Player {
    private:
        Hand hand;
        string name;
    public:
        Player();
        Player(string);
        string get_name();
        Hand get_hand();
        void deal_hand(Card, int);
        void show_hand();
        Card play_card(int);
        void shrink_hand(int);
        void grow_hand(Card&);
        bool check_hand(Card, int);
        bool check_eights();
        int get_eights();
        int get_n_cards();
        
};

#endif