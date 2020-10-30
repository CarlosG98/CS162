/******************************************************
** Program: tiger.cpp
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: function definitions for tiger class
** Input:
** Output:
******************************************************/
#include "tiger.h"

#include <iostream>

using namespace std;

Tiger::Tiger(){
    age = 48; //purchased tigers are always 4 years old (12months x 4 years)
    cost = 12000;
    babies = 3; //gives birth to 3 babies each time
    food_cost = 0; //will be decided on a monthly basis
    revenue = 1200;
}

void Tiger::set_food_cost(float food_base){
    food_cost = 5 * food_base; //each tigers food cost is 5x monthly food base cost
}

void Tiger::set_rev(){
    if(age < 6){
        revenue = 2400; //babies generate twice as much revenue
    }else{
        revenue = 1200;
    }
}
