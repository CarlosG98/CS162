/******************************************************
** Program: animal.h
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: header file for animal class
** Input:
** Output:
******************************************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;

class Animal {
    protected:
        int age;
        int cost;
        int babies;
        float food_cost;
        int revenue;
    private:
    public:
        Animal();
        int get_age();
        int get_cost();
        int get_babies();
        float get_food_cost();
        int get_revenue();
        void set_age(int); 
        void inc_age();
};

#endif