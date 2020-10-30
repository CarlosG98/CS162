/******************************************************
** Program: blackbear.h
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: header file for blackbear class
** Input:
** Output:
******************************************************/
#ifndef BLACKBEAR_H
#define BLACKBEAR_H

#include "animal.h"
#include <iostream>

using namespace std;

class Blackbear : public Animal { //derivation of animal class
    private:
    public:
        Blackbear();
        void set_food_cost(float);
        void set_rev();
};

#endif