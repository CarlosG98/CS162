/********************************************************************************************************************************************
 * Program: budget_buddy.cpp
 * Author: Carlos Gonzalez
 * Date: 01/14/20
 * Description: keeps track of a various users' transactions 
 * Input: text files, 
 * Output: user's account balance
 * ***************************************************************************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "budget_buddy.h"
 
using namespace std;
 
/*********************************************************
 * function: create_users
 * description: creates array of users' data
 * preconditions: array size
 * post conditions: empty arrays of users' data
 * *****************************************************/
user* create_users(int size){
    struct user* user;
    user = new struct user[size];
    
return user;
}
 
/*******************************************************
 * function: get_user_data
 * description: reads data from file to user struct
 * preconditions: empty user arrays
 * postconditions: array of users' data
 * *******************************************************/
void get_user_data(user* u, int size, ifstream &f){
 
    for(int i=0; i < size; i++){
        f >> u[i].name >> u[i].id >> u[i].password;
    }
}
 
/**********************************************************
 * function: create_budgets
 * description: creates a dynamic array of budgets of type struct budget.
 * Pre-conditions: desired size of array
 * Post-conditions: a dynamic array of budgets
 * *****************************************************/
budget* create_budgets(int size){
 
    struct budget* budget;
    budget = new struct budget[size];
 
return budget;
}
 
/************************************************************
 * function: create_transactions
 * description: creates a dynamic array of budgets of type struct transaction.
 * preconditions: desired size of array
 * post-condition: empty dynamic array of transactions.
 * ***********************************************************/
transaction* create_transactions(int size){
 
    struct transaction* transaction;
    transaction = new struct transaction[size];
 
return transaction;
}
 
/*****************************************************************************
 * function: get_transaction_data
 * description: reads data from txt file into transaction arrays
 * preconditions: empty transaction array, size of array, open file
 * post-conditions: transaction array with data
 * ***************************************************************************/
 
void get_transaction_data(transaction* t, int size, ifstream &f){
 
    for(int i=0; i < size; i++){
        f >> t[i].date >> t[i].amount >> t[i].description >> t[i].category;
    }
}
 
/****************************************************************
 * function: get_budget_data
 * description: reads data from a text file and assigns values to each budget member
 * pre-conditions: budget struct, number of budgets, file 
 * post-conditions: array of budgets with complete data
 * *********************************************************************/
void get_budgets_data(budget* budget, int size, ifstream &f){
    
    int count=0; //start at first budget entry
    while(count < size){
        f >> budget[count].id >> budget[count].balance >> budget[count].num_transactions;
        budget[count].t = create_transactions(budget[count].num_transactions); //creates array of transactions for current budget
        get_transaction_data(budget[count].t, budget[count].num_transactions, f); //read in data for each transaction for current budget 
        count++; //next budget
    }
}           
 
/****************************************************************
 * function: display_transactions
 * description: prints transactions data to screen
 * pre-conditions: user's budget's transactions
 * post-conditions: transactions printed on screen
 * *********************************************************************/
void display_transactions(transaction* t, int size){
    for(int i=0; i < size; i++){
        cout << "$" << t[i].amount << " " << t[i].date << " " << t[i].category << " " << t[i].description << endl;
    }
}
 
/****************************************************************
 * function: delete_budgets
 * description: deletes the dynamic array of budgets from the heap
 * pre-conditions: budget struct, size of array of budgets
 * post-conditions: deleted array
 * *********************************************************************/
void delete_budgets(budget* b, int size){
    for(int i=0; i < size; i++){
        delete [] b[i].t;
    }
    delete [] b;
}
 
/****************************************************************
 * function: login_exit
 * description: deletes dynamic arrays and exits program after 3 failed attempts
 * pre-conditions: user struct, budget struct, size of array of budgets 
 * post-conditions: graceful exit
 * *********************************************************************/
void login_exit(user* u, budget*b, int size_budgets){
    cout << "Too many failed login attempts. Exiting program..." << endl;
    delete [] u;
    delete_budgets(b, size_budgets);
    exit(EXIT_FAILURE);
}
 
/****************************************************************
 * function: user_login
 * description: handles the login process
 * pre-conditions: user structs, budget structs, size of user array, size of budget array
 * post-conditions: successful entry to program, or system exit depending on user 
 * *********************************************************************/
int user_login(user* u, budget* b, int size_users, int size_budgets){
 
    int user_id, x, fail = 0; 
    string user_pass;
    bool correct_login = false;
    do{
        cout << "User ID: ";
        cin >> user_id;
        cout << "Password: ";
        cin >> user_pass;
 
        for(int i=0; i < size_users; i++){
            if(user_id == u[i].id){ //if the id that user enters matches any id in the user array
                x = i; // set x equal to the corresponding spot in the array where the two matched
            }   
        }
        if((user_id != u[x].id) || (user_pass != u[x].password)){ //if either of the two credentials entered by user are incorrect
            cout << "Invalid login." << endl; 
            fail++; //increment fail attempts
        }       
        if(fail == 3){ //if user fails 3 times
            login_exit(u, b, size_budgets); //initiate exit process
        }
        if((user_id == u[x].id) && (user_pass == u[x].password)){ //if both credentials match
            correct_login = true; // user has succesfully logged in
            cout << "Logging in..." << endl; 
        }   
    }while(correct_login == false);
return x;
}
 
/****************************************************************
 * function: validate_comm_args
 * description: validates the command line arguments
 * pre-conditions: command line arguments 
 * post-conditions: correct file names and argument count
 * *********************************************************************/
void validate_comm_args(int a, char** v){
    char u[] = "users.txt"; //assume one text file is called users.txt
    char b[] = "budgets.txt"; //assume another file is called budgets.txt
    if(a != 3){ //if argument count is not 3
        cout << "Invalid amount of arguments." << endl;
        exit(EXIT_FAILURE); //exit program
    }
    if(((strcmp(u,v[1]) !=0) || (strcmp(b,v[2]) != 0)) && ((strcmp(b,v[1]) != 0) || (strcmp(u,v[2]) != 0))){ // if argument vectors 1 and 2 are not specifically labeled "budgets.txt" and "users.txt" or vice versa, exit.
        cout << "File(s) non-existent." << endl;
        exit(EXIT_FAILURE); //exit program
    }   
}
 
/****************************************************************
 * function: get_users_budget
 * description: loops through the array of budgets and retrieves the budget corresponding to the user
 * pre-conditions: user struct, budget struct, user's spot in the user struct array, number of budgets
 * post-conditions: user's corresponding budget
 * *********************************************************************/
int get_users_budget(user* u, budget* b, int user_num, int num_budgets){
    int x;
    for(int i=0; i < num_budgets; i++){
        if(b[i].id == u[user_num].id ){ //if the id corresponding to the budget matches the user's id
            x = i; // set x equal to the budget's integer in the array
        }
    }
return x;
}
 
/****************************************************************
 * function: display_user_info
 * description: greets the user upon successful login
 * pre-conditions: user struct, budget struct, user's integer in array, user's budget int in array
 * post-conditions: greeting screen
 * *********************************************************************/
void display_user_info(user* u, budget* b, int user_num, int user_budget){
    cout << "Welcome to Budget Buddy, " << u[user_num].name << "!" << endl;
    cout << "User ID: " << u[user_num].id << " | " << "Balance: $" << b[user_budget].balance << endl;
}
 
/*int check_x(char x){
    int y;
    bool check = false;
    if( x != '1' || x != '2'){
        check = false;
        while(check == false){
            cout << "Please enter 1 or 2: ";
            cin >> x;
            if( x == '1' || x == '2'){
                check = true;
                y =  x - 48;
            }else{
                check = false;
            }
        }
    }
return y;
}*/
 
void swap_cats(transaction* xp, int i, int j){
    transaction temp = xp[i];
    xp[i] = xp[j];
    xp[j] = temp;
}

void print_cats(budget* b, int user_budget, int decide){
    if(decide ==1 ){
        cout << "Transactions by category: " << endl;
        for(int i=0; i < b[user_budget].num_transactions; i++){
            cout << b[user_budget].t[i].date << " " << b[user_budget].t[i].amount << " " << b[user_budget].t[i].description << " " << b[user_budget].t[i].category << endl;
        }
    }
    
}
 
void sort_by_category(budget* b, int user_budget, int decide){
    int n = b[user_budget].num_transactions;
    for(int i=0; i < n-1; i++){
            if( b[user_budget].t[i].category[0] > b[user_budget].t[i+1].category[0]){
                swap_cats(b[user_budget].t, i, i+1);  
            }
        }
    
    print_cats(b, user_budget, decide);
}
 
/****************************************************************
 * function: decide_transactions
 * description: prompts user how they want to retrieve their transactions
 * pre-conditions: none 
 * post-conditions: how user wants their transaction
 * *********************************************************************/
int decide_transactions(){
    
    int x;
    
    cout << "Do you want transactions (1)printed on screen or (2)written on a file?";
    cin >> x; 
    //int y = check_x(x);
    //cout << "y: " << y << endl;
 
    return x;
    
}
 

void sort_transactions(budget* b, int sort_method, int user_budget, int decide){
    if(sort_method == 1){
        sort_by_category(b,user_budget,decide);
    }
    if(sort_method == 2){
        //sort_by_date(u,b);
    }
    if(sort_method == 3){
        //sort_by_amount(u,b);
    }
}

/****************************************************************
 * function: decide_sorting
 * description: prompts user how they wish to sort their transactions
 * pre-conditions: budget struct, user's budget's integer in array, how user want to retrieve transactions 
 * post-conditions: user's method of sorting
 * *********************************************************************/
void decide_sorting(budget* b, int user_budget, int decide){
    int x;
    cout << "How would you like your transactions sorted? (choose 1, 2, or 3):" << endl;
    cout << "(1) Sort by category" << endl;
    cout << "(2) Sort by date" << endl;
    cout << "(3) Sort by dollar amount" << endl;
    cin >> x;
    sort_transactions(b, x, user_budget, decide); 
}
 
int main(int argc, char** argv){
 
    validate_comm_args(argc, argv);
 
    int num_users, num_budgets;
    struct user* user;
    struct budget* budget;
    ifstream fin;
 
    fin.open("users.txt");
    if(fin.is_open()){
        fin >> num_users;
        user = create_users(num_users);
        get_user_data(user, num_users, fin);
        fin.close();
    }else{
        cout << "Error! Failed to open users.txt" << endl;
        return 1;
    }
 
    fin.open("budgets.txt");
    if(fin.is_open()){
        fin >> num_budgets;
        budget = create_budgets(num_budgets);
        get_budgets_data(budget, num_budgets, fin);
        fin.close();
    }else{
        cout << "Error! Failed to open budgets.txt" << endl;
        return 1;
    }
 
    int user_num = user_login(user, budget, num_users, num_budgets);
    int user_budget= get_users_budget(user, budget, user_num, num_budgets);
    display_user_info(user, budget, user_num, user_budget);
    int decide = decide_transactions();
    decide_sorting(budget, user_budget, decide);
 
 
 
return 0;
}   
     
 
 

