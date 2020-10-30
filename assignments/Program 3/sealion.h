/******************************************************
** Program: sealion.h
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: header file for sealion class
** Input:
** Output:
******************************************************/
#ifndef SEALION_H
#define SEALION_H

#include "animal.h"
#include <iostream>

using namespace std;

class Sealion : public Animal { //derivation of animal class
    private:
    public:
        Sealion();
        void set_food_cost(float);
        void add_bonus_rev(int);
        void set_rev();
};

#endif