#include <iostream>
#include "hand.h"
#include <string>

using namespace std;

Hand::Hand(){
    n_cards = 7;
    cards = new Card[n_cards];
    //cout << "Constructor called! " << endl;
}


Hand::Hand(const Hand& old_hand){
    this->n_cards = old_hand.n_cards;
    this->cards = new Card[this->n_cards];
    for(int i=0; i< this->n_cards; i++){
        this->cards[i] = old_hand.cards[i];
    }
    //cout << "Copy constructor called! " << endl;
}

Hand& Hand::operator= (const Hand& old_hand){
    delete [] this->cards;
    this->n_cards = old_hand.n_cards;
    this->cards = new Card[this->n_cards];
    for(int i=0; i < this->n_cards; i++){
        this->cards[i] = old_hand.cards[i];
    }
    //cout << "Assignment operator overload called! " << endl;
    return *this;
}

Hand::~Hand(){
    delete [] cards;
    //cout << "Hand destructor called! " << endl;
    
}

int Hand::get_n_cards(){
    return n_cards;
}

void Hand::start_hand(Card c1, int index){
    cards[index] = c1;
}

void Hand::show_hand(){
    cout << "YOUR CARDS: " << endl;
    for(int i=0; i < n_cards; i++){
        cout << "(" << i+1 << "): " << cards[i].get_srank() << " of " << cards[i].get_ssuit() << endl;
    }
}

void Hand::set_hands_cards(int num_cards){
    n_cards = num_cards;
}

Card Hand::play_card(int index){
    return cards[index];
}

void Hand::shrink_hand(int index){
    int c =0; //indicator for cards index in for loop
    Card * temp_hand = new Card [n_cards-1];
    n_cards--;
    for(int i=0; i < n_cards; i++){
        if(i == index){ //index is as seen in arr
            c++; //skip removed card
        }
        temp_hand[i] = cards[i+c]; //temp hand now has old hands cards except the one removed
    }
    delete [] cards;
    cards = temp_hand;
}

void Hand::grow_hand(Card& c1){
    Card* temp_hand = new Card[n_cards+1]; //temp hand is one card bigger than old hand
    for(int i=0; i < n_cards; i++){
        temp_hand[i] = cards[i]; //temp hand gets all cards in current hand
    }
    n_cards++;
    temp_hand[n_cards-1] = c1; //now we add the new card at the end
    delete [] cards;
    cards = temp_hand; //voila! new card in hand
}

bool Hand::check_hand(Card c1, int suit){
    bool has_card = false;
    int y= 0;
    if(suit == -1){
        for(int i=0; i < n_cards; i++){
            if(cards[i].get_rank() == c1.get_rank() || cards[i].get_suit() == c1.get_suit()){
                y++;
            }
            if(y > 0){
                has_card = true;
            }
        }
    }else{
        for(int i=0; i < n_cards; i++){
            if(cards[i].get_suit() == suit){
                y++;
            }
            if(y>0){
                has_card = true;
            }
        }
    }
    return has_card;
}

bool Hand::check_eights(){
    int y=0;
    for(int i=0; i < n_cards; i++){
        if(cards[i].get_rank() == 8){
            y++;
        }
    }
    if(y>0){
        return true;
    }else{
        return false;
    }
}

int Hand::get_eights(){
    int y;
    for(int i=0; i < n_cards; i++){
        if(cards[i].get_rank() == 8){
            y = i;
        }
    }
    return y;
}

