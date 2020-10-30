/*****************************************************************************
 * Program: maim.cpp
 * Author: Carlos Gonzalez  
 * Date: 3/12/20
 * Description: driver 
 * Input:
 * Output: runs program
 * **************************************************************************/
#include "linked_list.hpp"
#include <iostream>

using namespace std;

int main(){

    char again;
    do{
        Linked_List L;
        unsigned int list_length;
        char repeat;
        do{
            int num;
            cout << "Please enter a number: ";
            cin  >> num;
            list_length = L.push_front(num); 
            cout << "Do you want to enter another number? (y or n): ";
            cin >> repeat;
        }while( repeat == 'y');

        char sort;
        cout << "Sort ascending or descending? (a or d): ";
        cin >> sort;

        if(sort == 'a'){
            L.sort_ascending();
        }
        if(sort == 'd'){
            L.sort_descending();
        }

        L.print();
        L.check_primes();
        cout << "Do you want to do this again? (y or n): ";
        cin >> again;
        L.clear();
    }while(again == 'y');

return 0;
}
