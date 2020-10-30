/******************************************************
** Program: animal.cpp
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: function definitions for animal header file
** Input:
** Output:
******************************************************/
#include "animal.h"
#include <iostream>

using namespace std;

Animal::Animal(){
    age = 0;
    cost = 0;
    babies = 0;
    food_cost = 0; 
    revenue = 0; 
}

int Animal::get_age(){
    return age;
}

int Animal::get_cost(){
    return cost;
}

int Animal::get_babies(){
    return babies;
}

float Animal::get_food_cost(){
    return food_cost;
}

int Animal::get_revenue(){
    return revenue;
}

void Animal::set_age(int x){
    age = x;
}

void Animal::inc_age(){
    age++; //age is in terms of months
}