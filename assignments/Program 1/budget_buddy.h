/************************************************************************************************
 * Program: budget_buddy.h
 * Author: Carlos Gonzalez
 * Date: 01/14/20
 * Description: header file for budget_buddy.cpp
 * Input: none
 * Output: none(?)
 **************************************************************************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

struct user {
	string name;
	int id;
	string password;
};

struct budget {
	int id;
	float balance;
	int num_transactions;
	struct transaction* t;
};

struct transaction {
	float amount;
	string date;
	string category;
	string description;
};

user* create_users(int);
void get_user_data(user*, int, ifstream &);
budget* create_budgets(int);
transaction* create_transactions(int);
void get_transaction_data(transaction*, int, ifstream&);
void get_budgets_data(budget*, int, ifstream&);
void display_transactions(transaction*, int);
void delete_budgets(budget*, int );
void login_exit(user*, budget*, int);
int user_login(user*, budget*, int, int);
void validate_comm_args(int, char**);
int get_users_budget(user*, budget*, int , int );
void display_user_info(user*, budget*, int, int);
int decide_transactions();
void decide_sorting(budget*, int, int);


