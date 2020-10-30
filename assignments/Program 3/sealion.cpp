/******************************************************
** Program: sealion.cpp
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: function definitions for sealion class
** Input:
** Output:
******************************************************/
#include "sealion.h"
#include <iostream>

using namespace std;

Sealion::Sealion(){
    age = 48;
    cost = 700;
    babies = 1;
    food_cost = 0;
    revenue = 140;
}

void Sealion::set_food_cost(float base_food){
    food_cost = base_food; //sealions food cost is equal to the months base food cost
}

void Sealion::set_rev(){
    if(age < 6){
        revenue = 280;
    }else{
        revenue = 140;
    }
}

void Sealion::add_bonus_rev(int extra_rev){
    revenue += extra_rev; //extra_rev is generated from special event
}