#include <iostream>
#include <stdlib.h>
#include "./mult_div.h"

using namespace std;

int main(int argc, char ** argv){

    int rows = check_rows(argv);
    int cols = check_cols(argv);

    struct mult_div_values** table = create_table(rows, cols);
    set_mult_values(table, rows, cols);
    set_div_values(table, rows, cols);
    display_mult_table(table, rows, cols);
    display_div_table(table, rows, cols);
    delete_table(table, rows);
 
    int again;
    do{
        cout << "Would you like to make a new board? (0-no, 1-yes): ";
        cin >> again;
        if(again == 1){
        new_board();
        }
            
    }while(again == 1);

    return 0;
}
