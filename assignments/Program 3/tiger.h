/******************************************************
** Program: tiger.h
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: header file for tiger class
** Input:
** Output:
******************************************************/
#ifndef TIGER_H
#define TIGER_H

#include <iostream>
#include "animal.h"

using namespace std;

class Tiger : public Animal{ //derivation of animal class
    private:
    public:
      Tiger();  
      void set_food_cost(float);
      void set_rev();


};

#endif