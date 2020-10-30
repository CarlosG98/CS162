/******************************************************
** Program: zootycoon.h
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: header file for zootycoon game
** Input:
** Output:
******************************************************/
#include "animal.h"
#include "zoo.h"
#include "blackbear.h"
#include "tiger.h"
#include "sealion.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool check_bank_vs_species(Zoo&, int);
bool check_bank_vs_amount(Zoo&, int, int);
int get_species(Zoo&);
int get_species_amount(Zoo&, int);
void purchase_blackbears(Zoo&, int);
void purchase_tigers(Zoo&, int);
void purchase_sealions(Zoo&, int);
void purchase_animals(Zoo&, int, int);
void purchase(Zoo&);
void print_animals(Zoo&);
void sick_bear(Zoo&);
void sick_tiger(Zoo&);
void sick_sealion(Zoo&);
void sick_animal(Zoo&);
void make_baby_bears(Zoo&);
void make_baby_tigers(Zoo&);
void make_baby_sealion(Zoo&);
void make_baby(Zoo&);
void attendance_boom(Zoo&);
void monthly_revenue(Zoo&);
void make_regular_event(Zoo&);
void make_cheap_event(Zoo&);
void make_premium_event(Zoo&);
void start_event(Zoo&, int);
void calculate_food_cost(Zoo&, int);
bool check_bank(Zoo&);
void get_food_type(int*);
