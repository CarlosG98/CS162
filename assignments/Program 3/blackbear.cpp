/******************************************************
** Program: blackbear.cpp
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: function definitions for blackbear class
** Input:
** Output:
******************************************************/
#include "blackbear.h"
#include <iostream>

using namespace std;

Blackbear::Blackbear(){
    age = 48; //each new bear is 4 years old
    cost = 5000;
    babies = 2;
    food_cost = 0;
    revenue = 500;
}

void Blackbear::set_food_cost(float base_food){
    food_cost = 3 * base_food; //bears food cost is 3x monthly food base
}

void Blackbear::set_rev(){
    if(age < 6){
        revenue= 1000; //babies generate twice the revenue
    }else{
        revenue = 500;
    }
}