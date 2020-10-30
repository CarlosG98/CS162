/************************************************************************************************
 * Program: prog.cpp
 * Author: Carlos Gonzalez
 * Date: 01/14/20
 * Description: driver for budget buddy program
 * Input: none(?)
 * Output: budget buddy 
 **************************************************************************************************************************************/
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "budget_buddy.h"

using namespace std;

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
		//display_user_data(user, num_users);
		//delete [] user;
		fin.close();
	}else{
		cout << "Error! Failed to open users.txt" << endl;
		return 1;
	}

	fin.open("budgets.txt");
	if(fin.is_open()){
		fin >> num_budgets;
		budget = create_budgets(num_budgets);
		get_budget_data(budget, num_budgets, fin);
		//display_budget_data(budget, num_budgets);
		//delete_budgets(budget, num_budgets);
		fin.close();
	}else{
		cout << "Error! Failed to open budgets.txt" << endl;
		return 1;
	}

	int user_num = user_login(user, budget, num_users, num_budgets);
	int user_budget= get_users_budget(user, budget, user_num, num_budgets);
	/*cout << "user " << user_num << endl;
	cout << "users id " << user[user_num].id << endl;
	cout << "users budget id " << budget[user_budget].id << endl;*/
	display_user_info(user, budget, user_num, user_budget);
	int decide = decide_transactions();
	decide_sorting(budget, user_budget, decide);



return 0;
}	
	 

