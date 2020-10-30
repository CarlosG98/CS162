#include <iostream>
#include <stdlib.h>
#include "./mult_div.h"


using namespace std;

/*struct mult_div_values {
 *     int mult;
 *         float div;
 *         };
 *         */

int check_rows(char **a){
    int x = atoi(a[1]);
    while( x < 1){
        cout << "Enter a number greater than 0 for rows: ";
        cin >> x;
    }
    return x;
}

int check_cols(char **a){
    int x = atoi(a[2]);
    while(x < 1){
        cout << "Enter a number greater than 0 for columns: ";
        cin >> x;
    }
    return x;
}

mult_div_values** create_table(int m, int n){

   struct mult_div_values** table;

    table = new struct mult_div_values * [m];
    for(int i=0; i < m; i++){
        table[i] = new struct mult_div_values[n];
    }
    return table;
}

void set_mult_values(mult_div_values **table, int rows, int cols){
    for (int i=0; i < rows; i++){
        for(int j=0; j<cols; j++){
            table[i][j].mult = (i+1)*(j+1);
        }
    }
}

void set_div_values(mult_div_values** table, int rows, int cols){
    for (int i=0; i < rows; i++){
        for(int j=0; j<cols; j++){
            table[i][j].div = (i+1.00)/(j+1.00);
        }
    }
}

void display_mult_table( mult_div_values** table, int rows, int cols){
    cout << "Multiplication Table: " << endl;
    for(int i=0; i < rows; i++){
        for(int j=0; j < cols; j++){
            cout << table[i][j].mult << " ";
        }
        cout << endl;
    }
}

void display_div_table( mult_div_values** table, int rows, int cols){
    cout << "Division Table: " << endl;
    for(int i=0; i < rows; i++){
        for(int j=0; j < cols; j++){
            cout << table[i][j].div << " ";
        }
        cout << endl;
    }
}

void delete_table(mult_div_values** table, int rows){
    for(int i=0; i < rows; i++){
        delete [] table[i];
    }
    delete [] table;
}

void new_board(){

    int rows, cols;
    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter columns: ";
    cin >> cols;
    cout << endl;

    struct mult_div_values** table = create_table(rows, cols);
    set_mult_values(table, rows, cols);
    set_div_values(table, rows, cols);
    display_mult_table(table, rows, cols);
    display_div_table(table, rows, cols);
    delete_table(table, rows);
}
/*
 * int main(int argc, char ** argv){
 *
 *     int rows = check_rows(argv);
 *     int cols = check_cols(argv);
 *
 *     struct mult_div_values** table = create_table(rows, cols);
 *     set_mult_values(table, rows, cols);
 *     set_div_values(table, rows, cols);
 *     display_mult_table(table, rows, cols);
 *     display_div_table(table, rows, cols);
 *     delete_table(table, rows);
 *                                  
 *     int again;
 *     do{
 *        cout << "Would you like to make a new board? (0-no, 1-yes): ";
 *        cin >> again;
 *        
 *        if(again == 1){
 *        	new_board();
 *        }
 *                                                                                              
 *      }while(again == 1);
 *
 *  return 0;
   }
   */
