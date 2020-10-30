/******************************************************
** Program: zootycoon.cpp
** Author: Carlos Gonzalez
** Date: 02/14/2020
** Description: The game "Zoo Tycoon", where a user is the owner of a zoo and can purchase animals and take care of them.
** Input:
** Output:
******************************************************/
#include "animal.h"
#include "zoo.h"
#include "blackbear.h"
#include "tiger.h"
#include "sealion.h"
#include "zootycoon.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/********************************************************************************************
 * function: check_bank_vs_species
 * description: checks to see if the owner has enough money to purchase at least 1 of their desired animal
 * preconditions: unchecked user input
 * postconditions: checked user input
 * *******************************************************************************************/
bool check_bank_vs_species(Zoo& z, int species){
    bool affordable = true;
    int a = z.get_bank(); 
    if(species == 1){ //1 indicates blackbear
        if(a < 5000){ //each bear costs 5000
            affordable = false;
        }
    }
    if(species == 2){ //2 indicates tiger
        if(a < 12000){ //each tiger costs 12000
            affordable = false;
        }
    }
    if(species == 3){ //3 indicates sealion
        if(a < 700){ //each sealion costs 700
            affordable = false;
        }
    }
return affordable;
}

/********************************************************************************************
 * function: check_bank_vs_amount
 * description: checks if the owner has enough to buy 2 of their desired animal
 * preconditions: unchecked user input
 * postconditions: checked user input
 * *******************************************************************************************/
bool check_bank_vs_amount(Zoo& z, int species, int amount){
    bool affordable = true;
    if(species == 1 && amount == 2){ //if user wants 2 bears
        if(z.get_bank() < 10000){ //2 bears costs 10000
            affordable = false;
        }
    }
    if(species == 2 && amount == 2){ //if user wants 2 tigers
        if(z.get_bank() < 24000){ //2 tigers costs 24000
            affordable = false;
        }
    }
    if(species == 3 && amount == 2){ //if user wants 2 sealions
        if(z.get_bank() < 1400){ //2 sealions costs 14000
            affordable = false;
        } 
    }
return affordable;
}

/********************************************************************************************
 * function: get_species
 * description: asks the owner if they wish to purchase an animal, checks if they have enough money, asks for new input if check returns false
 * preconditions: user input
 * postconditions: checked and corrected user input
 * *******************************************************************************************/
int get_species(Zoo&z){
   int species;
   bool affordable;

   cout << "Which species would you like to purchase?" << endl;
   cout << "1: Blackbear ($5000 each) " << endl;
   cout << "2: Tiger ($12000 each)" << endl;
   cout << "3: Sealion ($700 each)" << endl;
   cout << "4: None" << endl;
   cin >> species;
   
   affordable = check_bank_vs_species(z, species); // checks if user has enough for at least 1 

   while(affordable == false){
       affordable = true;
       cout << "You do no have enough money for this animal. Please choose another: ";
       cin >> species;
       affordable = check_bank_vs_species(z, species); //checks input again
   }
   return species;
}

/********************************************************************************************
 * function: get_species_amount
 * description: asks the user if they want 1 or 2 of their desired animal, checks input, returns valid input
 * preconditions: user input
 * postconditions: checked and corrected user input
 * *******************************************************************************************/
int get_species_amount(Zoo& z, int species){
    int amount;
    bool affordable;
    cout << "How many would you like to purchase? (1 or 2): ";
    cin >> amount;

    affordable = check_bank_vs_amount(z, species, amount); //checks if user has enough for 2. No need to check for 1 since that is done when we check species input

    while(affordable == false){
        affordable = true;
        cout << "You do not have enough for 2. Please enter a different amount: ";
        cin >> amount;
        affordable = check_bank_vs_amount(z, species, amount); //checks input again
    }
    return amount;
}

/********************************************************************************************
 * function: purchase_blackbears
 * description: adds the correct number of blackbears according to user input, and subtracts money from their account
 * preconditions: user's amount input
 * postconditions: new blackbear array and new bank balance
 * *******************************************************************************************/
void purchase_blackbears(Zoo& z, int amount){
    if(amount == 1){
        z.add_blackbear(1); //add adult blackbear
        z.dec_bank(5000); //remove $5000 
    }
    if(amount == 2){
        z.add_blackbear(1);
        z.add_blackbear(1);
        z.dec_bank(10000);
    }
}

/********************************************************************************************
 * function: purchase_tigers
 * description: adds the correct number of tigers to array according to user input, subtracts money from their account
 * preconditions: user's amount input
 * postconditions: new tiger array and new bank balance
 * *******************************************************************************************/
void purchase_tigers(Zoo& z, int amount){
    if(amount == 1){
        z.add_tiger(1); //add adult tiger
        z.dec_bank(12000); //remove $12000
    }
    if(amount == 2){
        z.add_tiger(1);
        z.add_tiger(1);
        z.dec_bank(24000);
    }
}

/********************************************************************************************
 * function: purchase_sealions
 * description: adds the correct number of sealions to array according to user input, subtracts money from their account.
 * preconditions: user's amount input
 * postconditions: new sealion array and new bank balance
 * *******************************************************************************************/
void purchase_sealions(Zoo& z, int amount){
    if(amount == 1){
        z.add_sealion(1); //add adult sealion
        z.dec_bank(700); //remove $700
    }
    if(amount == 2){
        z.add_sealion(1);
        z.add_sealion(1);
        z.dec_bank(1400);
    }
}

/********************************************************************************************
 * function: purchase_animals
 * description: directs program to the appropriate function that will add the correct amount of species based on the user's input 
 * preconditions: user's valid species input and amount input
 * postconditions: directed to appropriate function 
 * *******************************************************************************************/
void purchase_animals(Zoo& z, int species, int amount){
    if(species == 1){
        purchase_blackbears(z, amount);
    }
    if(species == 2){
        purchase_tigers(z, amount);
    }
    if(species == 3){
        purchase_sealions(z, amount);
    }

}

/********************************************************************************************
 * function: purchase
 * description: initiates the purchasing proccess of animals
 * preconditions: 
 * postconditions: 
 * *******************************************************************************************/
void purchase(Zoo& z){
   int species = get_species(z);
   int species_amount;
   if(species < 4){ //4 means user wants none
    species_amount = get_species_amount(z, species);
   }

   purchase_animals(z, species, species_amount);
}

/********************************************************************************************
 * function: print_animals
 * description: Informs the user at the beginning of each month the amount of each animal they possess
 * preconditions:
 * postconditions:
 * *******************************************************************************************/
void print_animals(Zoo& z1){
    cout << "You have " << z1.get_num_blackbears() << " Black Bears and " << z1.get_num_blackbear_babies() << " baby Black Bears." << endl;
    cout << "You have " << z1.get_num_tigers() << " Tigers and " << z1.get_num_tiger_babies() << " baby Tigers." << endl;
    cout << "You have " << z1.get_num_sealions() << " Sealions and " << z1.get_num_sealion_babies() << " baby Sealions." << endl;
}

/********************************************************************************************
 * function: sick_bear
 * description: randomly chooses a bear, checks if that bear is a baby. If user has enough money, auto subtracts money from bank, else bear is removed.
 * preconditions: 
 * postconditions: resized array or decreased amount in users bank
 * *******************************************************************************************/
void sick_bear(Zoo& z){
    int rand_bb = rand() % z.get_num_blackbears(); //picks random bear in array
    if(z.get_blackbear_age(rand_bb) < 6){ //if bear is a baby
        if(z < 5000){ //if user does not have enough money
            cout << "Oh no! One of your baby Black Bears got sick and died! Could not afford medical fees... " << endl;
            z.remove_blackbear(rand_bb);
        }else{
            cout << "One of your baby Black Bears got sick! Removed $5000 from your bank account to cover medical fees. They are now healthy." << endl;
            z.dec_bank(5000);
        }
    }
    if(z.get_blackbear_age(rand_bb) >= 6){ //if bear is NOT a baby
        if(z < 2500){
            cout << "Oh no! One of your Black Bears got sick and died! Could not afford medical fees..." << endl;
            z.remove_blackbear(rand_bb);
        }else{
            cout << "One of your Black Bears got sick! Removed $2500 from your bank account to cover medical fees. They are now healthy." << endl;
            z.dec_bank(2500);
        }
    }
}

/********************************************************************************************
 * function: sick_tiger
 * description: randomly chooses a tiger in array, checks if its a baby. If user has enough money, auto subtracts from bank to heal them, or tiger is removed.
 * preconditions: 
 * postconditions: resized array or decreased bank amount
 * *******************************************************************************************/
void sick_tiger(Zoo& z){
    int rand_tiger = rand() % z.get_num_tigers(); //picks a random tiger in array
    if(z.get_tiger_age(rand_tiger) < 6){ //if tiger is a baby
        if(z < 12000){
            cout << "Oh no! One of your baby Tigers got sick and died! Could not afford medical fees..." << endl;
            z.remove_tiger(rand_tiger);
        }else{
            cout << "One of your baby Tigers got sick! Removed $12000 from your bank account to cover medical fees. They are now healthy." << endl;
            z.dec_bank(12000);
        }
    }
    if(z.get_tiger_age(rand_tiger) >= 6){
        if(z < 6000){
            cout << "Oh no! One of your Tigers got sick and died! Could not afford medical fees..." << endl;
            z.remove_tiger(rand_tiger);
        }else{
            cout << "One of your Tigers got sick! Removed $6000 from your bank account to cover medical fees. They are now healthy." << endl;
            z.dec_bank(6000);
        }
    }
}

/********************************************************************************************
 * function: sick_sealion
 * description: randomly chooses a sealion in array, checks if its a baby. If user has enough money, auto subtracts from bank to heal them, or sealion is removed.
 * preconditions:
 * postconditions: resized array or reduced bank amount
 * *******************************************************************************************/
void sick_sealion(Zoo& z){
    int rand_sealion = rand() % z.get_num_sealions(); //picks a random sealion in array
    if(z.get_sealion_age(rand_sealion) < 6){ //if random sealion is a baby
        if(z < 700){
            cout << "Oh no! One of your baby Sealions have died! Could not afford medical fees." << endl;
            z.remove_sealion(rand_sealion);
        }else{
            cout << "One of your baby Sealions got sick! Removed $700 from your bank account to cover medical fees. They are now healthy." << endl;
            z.dec_bank(700);
        }
    }
    if(z.get_sealion_age(rand_sealion) >= 6){
        if(z < 350){
            cout << "Oh no! One of your Sealions have died! Could not afford medical fees." << endl;
            z.remove_sealion(rand_sealion);
        }else{
            cout << "One of your Sealions got sick! Removed $350 from your bank account to cover medical fees. They are now healthy." << endl;
            z.dec_bank(350);
        }
    }
}

/********************************************************************************************
 * function: sick_animal
 * description: chooses which species will get sick and starts that process
 * preconditions:
 * postconditions:
 * *******************************************************************************************/
void sick_animal(Zoo& z){
    int rand_animal = rand() % 3; //choose 1 of three animals;
    if(rand_animal == 0 && z.get_num_blackbears() > 0){ 
        sick_bear(z);
    }
    if(rand_animal == 1 && z.get_num_tigers() > 0){
        sick_tiger(z);
    }
    if(rand_animal == 2 && z.get_num_sealions() > 0){
       sick_sealion(z);
    }

}

/********************************************************************************************
 * function: make_baby_bears
 * description: adds two baby bears to array 
 * preconditions:
 * postconditions:
 * *******************************************************************************************/
void make_baby_bears(Zoo& z){
    cout << "One of your Black Bears gave birth to 2 baby bears! " << endl;
    z.add_blackbear(0);
    z.add_blackbear(0);
}

/********************************************************************************************
 * function: make_baby_tigers
 * description: adds 3 baby tigers to array
 * preconditions:
 * postconditions:
 * *******************************************************************************************/
void make_baby_tigers(Zoo& z){
    cout << "One of your Tigers gave birth to 3 baby tigers! " << endl;
    z.add_tiger(0);
    z.add_tiger(0);
    z.add_tiger(0);
}

/********************************************************************************************
 * function: make_baby_sealion
 * description: adds a baby sealion to array
 * preconditions:
 * postconditions:
 * *******************************************************************************************/
void make_baby_sealion(Zoo& z){
    cout << "One of your Sealions gave birth to a baby sealion!" << endl;
    z.add_sealion(0);
}

/********************************************************************************************
 * function: make_baby
 * description: randomly chooses which species will have a baby and starts the process
 * preconditions: 
 * postconditions:
 * *******************************************************************************************/
void make_baby(Zoo& z){
    int rand_animal = rand() % 3; //randomly chooses a species
    if(rand_animal == 0 && z.get_num_blackbear_adults() > 0){
        make_baby_bears(z);
    }
    if(rand_animal == 1 && z.get_num_tiger_adults() > 0){
        make_baby_tigers(z);
    }
    if(rand_animal == 2 && z.get_num_sealion_adults() > 0){
        make_baby_sealion(z);
    }
}

/********************************************************************************************
 * function: attendance_boom
 * description: randomly generates extra revenue between $150 and $450 due to the user having sealions
 * preconditions:
 * postconditions:
 * *******************************************************************************************/
void attendance_boom(Zoo& z){
    int extra = rand() % 301 + 150;
    cout << "Woohoo! A boom in attendance this month. Your sealions have generated extra revenue! " << endl;
    z.sealion_extra(extra); //adds bonus to each sealion's revenue class member
}

/********************************************************************************************
 * function: monthly_revenue
 * description: retrieves the total amount of revenue the user has made based off the amount of animals in zoo
 * preconditions:
 * postconditions: increased bank amount
 * *******************************************************************************************/
void monthly_revenue(Zoo& z){
    int monthly_r;
    if(z.get_month() > 0){
        monthly_r = z.get_total_revenue();
        cout << "It's payday! Adding $" << monthly_r << " to bank account..." << endl;
        z.inc_bank(monthly_r);
    }
}

/********************************************************************************************
 * function: make_regular_event
 * description: if user chose to buy regular food, each event has an equal chance to occur
 * preconditions:
 * postconditions:
 * *******************************************************************************************/
void make_regular_event(Zoo& z){
    int event = rand() % 4;
    if(event == 0){
        sick_animal(z);
    }
    if(event == 1){
        make_baby(z);
    }
    if(event == 2 && z.get_num_sealions() > 0){
        attendance_boom(z);
    }
    if(event == 3){
        cout << "No special event this month." << endl;
    } 
}

/********************************************************************************************
 * function: make_cheap_event
 * description: if user chose cheap food, double the probability of an animal getting sick
 * preconditions:
 * postconditions:
 * *******************************************************************************************/
void make_cheap_event(Zoo& z){
    int event = rand() % 4;
    if(event == 0 || event == 1){
        sick_animal(z);
    }
    if(event == 2){
        make_baby(z);
    }
    if(event == 3){
        attendance_boom(z);
    }
}

/********************************************************************************************
 * function: make_premium_event
 * description: if user chose premium food, probability of animal sickness is cut in half
 * preconditions:
 * postconditions:
 * *******************************************************************************************/
void make_premium_event(Zoo& z){
    int event = rand() % 8;
    if(event == 0){
        sick_animal(z);
    }
    if(event == 1 || event == 2){
        make_baby(z);
    }
    if(event == 3 || event == 4){
        attendance_boom(z);
    }
    if(event >= 5){
        cout << "No special event this month." << endl;
    }
}

/********************************************************************************************
 * function: start_event
 * description: initiates the special event process based off user's last month chosen food type
 * preconditions:
 * postconditions:
 * *******************************************************************************************/
void start_event(Zoo& z, int food_type){
    if(z.get_month() > 0){
       if(food_type == 1){ //if user chose regular food
           make_regular_event(z);
       }
       if(food_type == 2){ //if user chose premium food
           make_premium_event(z);
       }
       if(food_type == 3){ //is user chose cheap food
           make_cheap_event(z);
       }
    }
}

/********************************************************************************************
 * function: calculate_food_cost
 * description: calculates current months food cost based off of number of animals and last month's cost and food type
 * preconditions:
 * postconditions: subtracted total from user's bank
 * *******************************************************************************************/
void calculate_food_cost(Zoo& z, int food_type){
    float monthly_base = z.get_base_food_cost(); //gets current months base food cost
    float monthly_food_cost;
    if(z.get_month() > 0){
        float percent = rand() % 41 + 80; //generate a percent between 80 and 120
        percent = percent / 100;
        monthly_base = percent * z.get_base_food_cost(); //new months base is a percentage of last months
        z.set_base_food_cost(monthly_base); //set for next months payment
    }
    z.set_animals_food(monthly_base); //sets each animals animals food cost for current month
    monthly_food_cost = z.get_total_food(); //gets total food cost
    if(food_type == 2){
        monthly_food_cost = monthly_food_cost * 2; //if user chose premium food, double price
    }
    if(food_type == 3){
        monthly_food_cost = monthly_food_cost / 2; //if user chose cheap, half price
    }
    cout << "Time to pay for the animals' food! Subtracting $" << monthly_food_cost << " from bank account..." << endl;
    z.dec_bank(monthly_food_cost); //subtract food cost from users bank

}

/********************************************************************************************
 * function: check_bank
 * description: checks the users bank throughout the game to see if they went bankrupt
 * preconditions:
 * postconditions: true if out of money, false otherwise
 * *******************************************************************************************/
bool check_bank(Zoo& z){
    if(z.get_bank() <= 0){
        return true;
    }else{
        return false;
    }
}

/********************************************************************************************
 * function: get_food_type
 * description: asks the user which food type they want next month, updates food_type variable for next months use
 * preconditions:
 * postconditions:
 * *******************************************************************************************/
void get_food_type(int* type){
    int x;
    cout << endl;
    cout << "What type of food do you wish to purchase for next month?" << endl;
    cout << "1: Regular (normal food, 1x)" << endl;
    cout << "2: Premium (half probability for animal sickness, 2x price of regular)" << endl;
    cout << "3: Cheap (double sickness probability, half price of regular)" << endl;
    cin >> x;
    *type = x;
}