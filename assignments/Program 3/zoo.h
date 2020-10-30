/******************************************************
** Program: zoo.h
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: header file for zoo class 
** Input:
** Output:
******************************************************/
#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include "tiger.h"
#include "sealion.h"
#include "blackbear.h"

using namespace std;

class Zoo {
    private: 
        Tiger* Tigers;
        Sealion* Sealions;
        Blackbear* Blackbears;
        int num_tigers;
        int num_sealions;
        int num_blackbears;
        int num_tiger_adults;
        int num_tiger_babies;
        int num_sealion_adults;
        int num_sealion_babies;
        int num_blackbear_adults;
        int num_blackbear_babies;
        float Bank;
        int month;
        int base_food_cost;
    public:
        Zoo();
        ~Zoo();
        Zoo(const Zoo&);
        Zoo& operator=(const Zoo&);
        friend bool operator<(const Zoo&, int);
        int get_num_tigers();
        int get_num_sealions();
        int get_num_blackbears();
        int get_num_tiger_adults();
        int get_num_tiger_babies();
        int get_num_sealion_adults();
        int get_num_sealion_babies();
        int get_num_blackbear_adults();
        int get_num_blackbear_babies();
        float get_bank();
        int get_month();
        int get_sealion_age(int);
        int get_tiger_age(int);
        int get_blackbear_age(int);
        int get_base_food_cost();
        float get_total_food();
        void set_base_food_cost(float);
        void set_animals_food(float);
        void inc_month();
        void dec_bank(float);
        void inc_bank(float);
        void add_tiger(int);
        void remove_tiger(int);
        void add_sealion(int);
        void remove_sealion(int);
        void add_blackbear(int);
        void remove_blackbear(int);
        int get_total_revenue();
        void inc_all_ages();
        void sealion_extra(int);       
};


#endif 