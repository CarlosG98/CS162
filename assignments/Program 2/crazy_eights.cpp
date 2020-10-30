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


using namespace std;

/**************************************************************************************
 * function: start_deck
 * description: creates a deck, shuffles it, force set stocks num_card=0, deal cards to players, take 15th card in deck and sends to pile
 * pre-conditions: empty game
 * post-conditions: game begins
 * *************************************************************************************/
void start_deck(Game& g1){
    g1.create_deck();
    g1.shuffle_deck();
    g1.set_stock();
    g1.distribute_cards();
    g1.add_to_stock();
    
}

/**************************************************************************************
 * function: get_players_name
 * description: asks the user for their name
 * pre-conditions:
 * post-conditions: 
 * *************************************************************************************/
string get_players_name(){
    string username;
    cout << "------STARTING NEW GAME OF CRAZY EIGHTS!------ " << endl;
    cout << "Enter your name: ";
    cin >> username;
return username;
}

/**************************************************************************************
 * function: check_card
 * description: compares the card the player wishes to place on the pile to the top card on the pile
 * pre-conditions: players int, and players card's index
 * post-conditions: boolean
 * *************************************************************************************/
bool check_card(Game& g1, int card, int plyr){ //for very first turn
    Card c = g1.get_player_card(plyr, card); //gets the card from players hand
    Card d = g1.get_top_card(); //top card of stock
    if(c.get_rank() == d.get_rank() || c.get_suit() == d.get_suit()){
        return true;
    }else{
        return false;
    }
}

/**************************************************************************************
 * function: check_card_pt2
 * description: this function is similar to pt1, but works for both computer and player and checks against chosen suit
 * pre-conditions: players int, players card, players suit that opponent must match
 * post-conditions: bool
 * *************************************************************************************/
bool check_card_pt2(Game& g1, int card, int plyr, int suit){ //after players first turn, and for every computers turn
    Card c = g1.get_player_card(plyr, card); //return card that player wishes to place on pile
    Card d = g1.get_top_card(); //get top card
    bool check;
    if(suit == -1){ //if opponents last move did not place an eight
        if(c.get_rank() == d.get_rank() || c.get_suit() == d.get_suit()){ //compare cards
            check = true;
        }else{
            check = false;
        }
    }
    if(suit >= 0){ //if opponent placed an eight, card must match the suit they declared
        if(c.get_suit() == suit){
            check = true;
        }else{
            check = false;
        }
    }
    return check;
}

/**************************************************************************************
 * function: get_valid_card
 * description: forces player to pick a card that matches top of pile
 * pre-conditions: bool
 * post-conditions: card index
 * *************************************************************************************/
int get_valid_card(bool &valid, Game& g1){
    int val_card;
    while(valid == false){ //while player did not request to place a valid card
        cout << "Card does not match top card's rank or suit. Please choose a new card: ";
        cin >> val_card;
        val_card--; //decrement users card to get its int as an index
        valid = check_card(g1, val_card, 1); //always check card matches
    }
    return val_card;
}

/**************************************************************************************
 * function: get_valid_card_computer
 * description: forces computer to generate num that matches top of stack or users chosen suit
 * pre-conditions: players chosen suit as an int, bool
 * post-conditions: card index
 * *************************************************************************************/
int get_valid_card_computer(bool &valid, Game& g1, int players_suit){
    int val_card;
    while(valid == false){ //while card does not match top of pile
        val_card = rand() % g1.get_hand_n_cards(0) +1; //generate a card
        valid = check_card_pt2(g1, val_card, 0, players_suit); //check new card
    }
    return val_card;
}

/**************************************************************************************
 * function: draw_card
 * description: if player doesnt have cards that match top of pile, auto draw from deck
 * pre-conditions: plyr
 * post-conditions: more cards in users hand
 * *************************************************************************************/
void draw_card(Game& g1, int plyr){
    Card c1 = g1.get_top_card(); //gets top card
    bool has_card;
    do{
        has_card = g1.check_hand(c1, plyr, -1); //checks if user has a playable card
        if(has_card == false){ //if no
            if(plyr == 1){
                cout << "TOP CARD: " ; g1.show_top_card();
                cout << "NO MATCHING CARDS. TOOK FROM DECK." << endl;
                g1.grow_hand(1); //grab from deck for user
                g1.show_player_hand(1); //show users hand
            }
            if(plyr == 0){
                g1.grow_hand(0);//grab from deck for computer
            }
        }
        has_card = g1.check_hand(c1, plyr, -1); //check hand again
    }while( has_card == false);
}

/**************************************************************************************
 * function: draw_card_pt2
 * description: pretty much the same as above. this time i included players chosen suit as a parameter
 * pre-conditions:
 * post-conditions: 
 * *************************************************************************************/
void draw_card_pt2(Game& g1, int plyr, int suit){
    Card c1 = g1.get_top_card(); //gets top card
    bool has_card;
    if(suit == -1){ //if last move was a normal turn
        do{
            has_card = g1.check_hand(c1, plyr, suit);//check if hand has playable card
            if(has_card == false){
                if(plyr == 1){
                    cout << "TOP CARD: " ; g1.show_top_card();
                    cout << "NO MATCHING CARDS. TOOK FROM DECK." << endl;
                    g1.grow_hand(1);//grab from deck for user
                    g1.show_player_hand(1);
                }
                if(plyr == 0){
                    g1.grow_hand(0);//grab from deck for computer
                }
            }
            has_card = g1.check_hand(c1, plyr, suit);//check hand again
        }while( has_card == false);
    }
}

/**************************************************************************************
 * function: check_eights
 * description: for user only, checks if they possess an eight in their hand and asks if they wish to play it
 * pre-conditions:
 * post-conditions: bool
 * *************************************************************************************/
bool check_eights(Game& g1){ //checks players eights
    bool played_eight, eights = g1.check_eights(1); //check if user has a card of 8
    int play_eight, suit;
    if(eights == true){
        cout << "You have a card of rank 8! Would you like to play this card? (0-no, 1-yes): ";
        cin >> play_eight;
            if(play_eight == 1){ //if user wants to play their 8
                int index = g1.get_eights(1); //get the cards index
                g1.pass_card(1, index); //send to pile
                g1.shrink_hand(1, index); //remove card from hand
                played_eight = true;
                return played_eight;
            }
            if(play_eight == 0){
                played_eight = false;
                return played_eight;
            }
    }
    return eights;
}

/**************************************************************************************
 * function: player_first_turn_part2
 * description: continues from function - player_first_turn
 * pre-conditions:
 * post-conditions: 
 * *************************************************************************************/
void player_first_turn_part2(Game &g1){
        draw_card(g1, 1); //check for playable card
        int card;
        cout << "Which card would you like to play? ";
        cin >> card;
        card--; //now matches index in arr
        bool valid = check_card(g1, card, 1);//call function to check if card matches top of stock
        if(valid == true){
            g1.pass_card(1, card); // if valid card, sends card to pile
            g1.shrink_hand(1,card);//remove card from players hand
        }else{
            int val_card = get_valid_card(valid, g1); //gets a valid card
            g1.pass_card(1, val_card); //passes valid card
            g1.shrink_hand(1, val_card); //removes card from hand
        }
}

/**************************************************************************************
 * function: player_first_turn
 * description: user always makes first move, following this processs
 * pre-conditions:
 * post-conditions: return 0-3 if they played their eight, -1 if normal move
 * *************************************************************************************/
int player_first_turn(Game& g1){
    int suit;
    g1.show_player_hand(1);
    bool eights = check_eights(g1); //checks user has an 8
    if(eights == false){
        player_first_turn_part2(g1);
        suit = -1;
    }
    if(eights == true){
        cout << "What suit should the opponent play? (1)Club (2)Diamonds (3)Hearts (4)Spades: ";
        cin >> suit;
        suit = suit -1;
    }
return suit;
}

/**************************************************************************************
 * function: check_com_eights
 * description: checks if computer has an eight in their hand
 * pre-conditions:
 * post-conditions: bool
 * *************************************************************************************/
bool check_com_eights(Game& g1){ //checks computers eights
    bool eights = g1.check_eights(0);
    int suit;
    if(eights == true){ //if computer has an 8, it will always play it
        int index = g1.get_eights(0);
        g1.pass_card(0, index);
        g1.shrink_hand(0, index);
    }          
    return eights;
}

/**************************************************************************************
 * function: get_valid_card_com
 * description: forces computer to generate a card that matches top of pile
 * pre-conditions:
 * post-conditions: computers card as an index in their hand's array
 * *************************************************************************************/
int get_valid_card_com(bool &valid, Game& g1, int plyr_suit){
    int val_card;
    while(valid == false){ // if computers generated card doesnt match top of pile, or players chosen suit
        val_card = rand() % g1.get_hand_n_cards(0); //generate new card
        valid = check_card_pt2(g1, val_card, 0, plyr_suit); //check card
    }
    return val_card;
}

/**************************************************************************************
 * function: print_com_suit
 * description: tells the user which suit the computer has chosen for them to match
 * pre-conditions:
 * post-conditions: 
 * *************************************************************************************/
void print_coms_suit(int a){
    if(a == 0){
        cout << "COMPUTERS SUIT: CLUBS" << endl;
    }
    if(a == 1){
        cout << "COMPUTERS SUIT: DIAMONDS" << endl;
    }
    if(a == 2){
        cout << "COMPUTERS SUIT: HEARTS" << endl;
    }
    if(a == 3){
        cout << "COMPUTERS SUIT: SPADES" << endl;
    }
}

/**************************************************************************************
 * function: computers_turn
 * description: process for the computers turn
 * pre-conditions:
 * post-conditions: returns 0-3 if they played an eight, -1 if normal move
 * *************************************************************************************/
int computers_turn(Game& g1, int players_suit){
    int suit, play_card;
    bool eights = check_com_eights(g1); //checks for card of 8
    if(eights == false){
        draw_card_pt2(g1, 0, players_suit); //checks if has playable card, if not, draws from deck
        play_card = rand() % g1.get_hand_n_cards(0) ; //generates card as an index
        int a = g1.get_hand_n_cards(0);
        bool valid = check_card_pt2(g1, play_card, 0, players_suit);//call function to check if card matches top of stock
        if(valid == true){ //if matches
            g1.pass_card(0, play_card); // if valid card, sends card to pile
            g1.shrink_hand(0, play_card);//remove card from players hand
        }else{ //if card doesnt match
            int val_card = get_valid_card_com(valid, g1, players_suit); //gets a valid card
            g1.pass_card(0, val_card); //passes valid card
            g1.shrink_hand(0, val_card); //removes card from hand
        }
        suit = -1; //-1 indicates the process above
    }
    if(eights == true){ //if computer played their 8
        suit = rand() % 4; // generates a num 0-3, which indicates the 4 suits
        print_coms_suit(suit); //tell user which suit was chosen
    }
return suit;
}


/**************************************************************************************
 * function: get_valid_card_pt2
 * description:forces user to pick a matching card
 * pre-conditions:
 * post-conditions: 
 * *************************************************************************************/
int get_valid_card_pt2(bool &valid, Game& g1, int computers_suit){
    int val_card;
    while(valid == false){
        if(computers_suit == -1){ //if computer didnt choose a suit
        cout << "Card does not match top card's rank or suit. Please choose a new card: ";
        }else{
            cout << "Card does not match computers chosen suit." << endl;
        }
        cin >> val_card;
        val_card--; //now as an index
        valid = check_card_pt2(g1, val_card, 1, computers_suit);
    }
    return val_card;
}

/**************************************************************************************
 * function: player_next_turn_part2
 * description: continues the process of first function - player_next_turn
 * pre-conditions:
 * post-conditions: 
 * *************************************************************************************/
void player_next_turn_part2(Game &g1, int computers_suit){
        draw_card_pt2(g1, 1, computers_suit); //checks hand for playable card
        int card;
        cout << "Which card would you like to play? ";
        cin >> card;
        card--; //players card as an index
        bool valid = check_card_pt2(g1, card, 1, computers_suit);//call function to check if card matches top of stock
        if(valid == true){
            g1.pass_card(1, card); // if valid card, sends card to pile
            g1.shrink_hand(1,card);//remove card from players hand
        }else{
            int val_card = get_valid_card_pt2(valid, g1, computers_suit); //gets a valid card as index
            g1.pass_card(1, val_card); //passes valid card
            g1.shrink_hand(1, val_card); //removes card from hand
        }
}

/**************************************************************************************
 * function: player_next_turn
 * description: process for every player's turn after their very first turn
 * pre-conditions:
 * post-conditions: 0-3 if they played eight, -1 if normal move
 * *************************************************************************************/
int player_next_turn(Game& g1, int computers_suit){
    int suit;
    bool eights = check_eights(g1);
    if(eights == false){
        player_next_turn_part2(g1, computers_suit);
        suit = -1;
    }
    if(eights == true){
        cout << "What suit should the opponent play? (1)Club (2)Diamonds (3)Hearts (4)Spades: ";
        cin >> suit;
        suit = suit -1;
    }
return suit;
}

/**************************************************************************************
 * function:update_num
 * description: after every move, the player returns a num to pass to opponents turn function.
 *              this decides how they must play their turn. I use this function to update the num
 *              so that it works with a for loop.
 * pre-conditions:
 * post-conditions: updated players-turn value
 * *************************************************************************************/
void update_num(int* xp, int* yp){
    *xp = *yp;
}