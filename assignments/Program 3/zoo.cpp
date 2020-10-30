#include "zoo.h"
#include <iostream>

using namespace std;

Zoo::Zoo(){
    Bank = 100000; //owners starts game with $100000 in bank
    Tigers = new Tiger[0];
    Blackbears = new Blackbear[0];
    Sealions = new Sealion[0];

    num_sealions = 0;
    num_tigers = 0;
    num_blackbears = 0;

    num_tiger_adults = 0;
    num_tiger_babies = 0;
    num_blackbear_adults = 0;
    num_blackbear_babies = 0;
    num_sealion_adults = 0;
    num_sealion_babies = 0;

    base_food_cost = 80;
    month = 0;

}

Zoo::Zoo(const Zoo& old_zoo){ //copy constructor
    this->num_blackbears = old_zoo.num_blackbears;
    this->num_sealions = old_zoo.num_sealions;
    this->num_tigers = old_zoo.num_tigers;

    for(int i=0; i < this->num_tigers; i++){
        this->Tigers[i] = old_zoo.Tigers[i];
    }
    for (int i = 0; i < this->num_sealions; i++){
        this->Sealions[i] = old_zoo.Sealions[i];
    }
    for (int i = 0; i < this->num_blackbears; i++){
        this->Blackbears[i] = old_zoo.Blackbears[i];
    }    
}

Zoo& Zoo::operator=(const Zoo& old_zoo){ //assignment operator overload
    delete [] this->Blackbears;
    delete [] this->Tigers;
    delete [] this->Sealions;

    for(int i=0; i < this->num_tigers; i++){
        this->Tigers[i] = old_zoo.Tigers[i];
    }
    for (int i = 0; i < this->num_sealions; i++){
        this->Sealions[i] = old_zoo.Sealions[i];
    }
    for (int i = 0; i < this->num_blackbears; i++){
        this->Blackbears[i] = old_zoo.Blackbears[i];
    }    
    return *this;
}

bool operator<(const Zoo& z, const int x){ //< operator overload
    return z.Bank < x;
}

float Zoo::get_bank(){
    return Bank;
}

int Zoo::get_month(){
    return month;
}

int Zoo::get_num_tigers(){
    return num_tigers;
}

int Zoo::get_num_tiger_adults(){
    return num_tiger_adults;
}

int Zoo::get_num_tiger_babies(){
    return num_tiger_babies;
}

int Zoo::get_num_sealions(){
    return num_sealions;
}

int Zoo::get_num_sealion_adults(){
    return num_sealion_adults;
}

int Zoo::get_num_sealion_babies(){
    return num_sealion_babies;
}

int Zoo::get_num_blackbears(){
    return num_blackbears;
}

int Zoo::get_num_blackbear_adults(){
    return num_blackbear_adults;
}

int Zoo::get_num_blackbear_babies(){
    return num_blackbear_babies;
}

int Zoo::get_sealion_age(int index){
    return Sealions[index].get_age();
}

int Zoo::get_tiger_age(int index){
    return Tigers[index].get_age();
}

int Zoo::get_blackbear_age(int index){
    return Blackbears[index].get_age();
}

int Zoo::get_base_food_cost(){
    return base_food_cost;
}

void Zoo::set_base_food_cost(float new_base){
    base_food_cost = new_base;
}

void Zoo::set_animals_food(float monthly_base){ //sets each animals food cost for given month
    for(int i=0; i < num_blackbears; i++){
        Blackbears[i].set_food_cost(monthly_base); 
    }
    for(int i=0; i < num_tigers; i++){
        Tigers[i].set_food_cost(monthly_base);
    }
    for(int i =0; i < num_sealions; i++){
        Sealions[i].set_food_cost(monthly_base);
    }
}

float Zoo::get_total_food(){ //sums up the total food cost for each animal in zoo
    float total = 0;
    for(int i=0; i < num_sealions; i++){
        total += Sealions[i].get_food_cost();
    }
    for(int i=0; i < num_tigers; i++){
        total += Tigers[i].get_food_cost();
    }
    for(int i=0; i < num_blackbears; i++){
        total += Blackbears[i].get_food_cost();
    }
return total;
}

void Zoo::inc_month(){
    month++;
}

void Zoo::inc_bank(float x){
    Bank += x;
}

void Zoo::dec_bank(float x){
    Bank -= x;
}

void Zoo::add_tiger(int x){
        Tiger* temp = new Tiger[num_tigers+1];
        for(int i = 0; i < num_tigers; i++){
            temp[i] = Tigers[i];
        }
        Tiger t1;
        if(x == 0){ //0 means add baby tiger, anything else means adult tiger
            t1.set_age(0);
            t1.set_rev();
            num_tiger_babies++;
        }else{
            num_tiger_adults++;
        }
        temp[num_tigers] = t1;
        num_tigers++;
        delete [] Tigers;
        Tigers = temp;
}

void Zoo::remove_tiger(int index){
    int c =0; //indicator for the Tigers index in for loop
    Tiger* temp = new Tiger[num_tigers-1];
    num_tigers--;
    if(Tigers[index].get_age() < 6){
        num_tiger_babies--;
    }
    if(Tigers[index].get_age() >= 48){
        num_tiger_adults--;
    }
    for(int i=0; i < num_tigers; i++){
        if(i == index){ //index is as seen in arr
            c++; //skips tiger we wish to remove in arr
        }
        temp[i] = Tigers[i+c]; //temp equals tiger arr without dead tiger
    }
    delete [] Tigers;
    Tigers = temp;
}

void Zoo::add_sealion(int x){
        Sealion* temp = new Sealion[num_sealions+1];
        for(int i = 0; i < num_sealions; i++){
            temp[i] = Sealions[i];
        }
        Sealion s1;
        if(x == 0){ //0 means add baby sealion, anything else means adult sealion
            s1.set_age(0);
            s1.set_rev();
            num_sealion_babies++;
        }else{
            num_sealion_adults++;
        }
        temp[num_sealions] = s1;
        num_sealions++;
        delete [] Sealions;
        Sealions = temp;
}

void Zoo::remove_sealion(int index){
    int c =0; //indicator for the Sealion index in for loop
    Sealion* temp = new Sealion[num_sealions-1];
    num_sealions--;
    if(Sealions[index].get_age() < 6){
        num_sealion_babies--;
    }
    if(Sealions[index].get_age() >= 48){
        num_sealion_adults--;
    }
    for(int i=0; i < num_sealions; i++){
        if(i == index){ //index is as seen in arr
            c++; //skips sealion we wish to remove in arr
        }
        temp[i] = Sealions[i+c]; //temp equals tiger arr without dead sealion
    }
    delete [] Sealions;
    Sealions = temp;
}

void Zoo::add_blackbear(int x){
        Blackbear* temp = new Blackbear[num_blackbears+1];
        for(int i = 0; i < num_blackbears; i++){
            temp[i] = Blackbears[i];
        }
        Blackbear b1;
        if(x == 0){ //0 means add baby blackbear, anything else means adult blackbear
            b1.set_age(0);
            b1.set_rev();
            num_blackbear_babies++;
        }else{
            num_blackbear_adults++;
        }
        temp[num_blackbears] = b1;
        num_blackbears++;
        delete [] Blackbears;
        Blackbears = temp;
}

void Zoo::remove_blackbear(int index){
    int c =0; //indicator for the blackbears index in for loop
    Blackbear* temp = new Blackbear[num_blackbears-1];
    num_blackbears--;
    if(Blackbears[index].get_age() < 6){
        num_blackbear_babies--;
    }
    if(Blackbears[index].get_age() >=48){
        num_blackbear_adults--;
    }
    for(int i=0; i < num_blackbears; i++){
        if(i == index){ //index is as seen in arr
            c++; //skips blackbear we wish to remove in arr
        }
        temp[i] = Blackbears[i+c]; //temp equals blackbear arr without dead blackbear
    }
    delete [] Blackbears;
    Blackbears = temp;
}

int Zoo::get_total_revenue(){ //sums up all the revenue produced by each animal in the zoo
    int total_rev = 0;
    for(int i=0; i < num_sealions; i++){
        total_rev += Sealions[i].get_revenue();
    }
    for(int i=0; i < num_tigers; i++){
        total_rev += Tigers[i].get_revenue();
    }
    for(int i=0; i < num_blackbears; i++){
        total_rev += Blackbears[i].get_revenue();
    }
    return total_rev;
}

void Zoo::inc_all_ages(){ //each month, the age of each animal is increased by 1
    if(month > 0){
        for(int i=0; i < num_blackbears; i++){
            Blackbears[i].inc_age();
            if(Blackbears[i].get_age() == 6){ //babies are less than 6 months old
                num_blackbear_babies--;
            }
            if(Blackbears[i].get_age() == 48){ //adults are 4 years or older
                num_blackbear_adults++;
            }
            Blackbears[i].set_rev(); //resets bears revenue
        }
        for(int i=0; i < num_sealions; i++){
            Sealions[i].inc_age();
            if(Sealions[i].get_age() == 6){ 
                num_sealion_babies--;
            }
            if(Sealions[i].get_age() == 48){
                num_sealion_adults++;
            }
            Sealions[i].set_rev(); //resets sealions revenue
        }
        for(int i=0; i < num_tigers; i++){
            Tigers[i].inc_age();
            if(Tigers[i].get_age() == 6){
                num_tiger_babies--;
            }
            if(Tigers[i].get_age() ==48){
                num_tiger_adults++;
            }
            Tigers[i].set_rev(); //resetes tigers revenue
        }
    }
}

void Zoo::sealion_extra(int extra){
    for(int i=0; i < num_sealions; i++){
        Sealions[i].add_bonus_rev(extra);
    }
}

Zoo::~Zoo(){ //Zoo destructor
    delete [] Tigers;
    delete [] Blackbears;
    delete [] Sealions;
}