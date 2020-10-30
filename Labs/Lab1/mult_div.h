#include <iostream>
#include <stdlib.h>

using namespace std;

	struct mult_div_values {
    		int mult;
     		float div;
	};

	//bool is_valid_dimensions(char *, char *);
	mult_div_values** create_table(int, int);
	void set_mult_values(mult_div_values **, int, int);
	void set_div_values(mult_div_values **, int, int);
	void display_mult_table(mult_div_values**, int, int);
	void display_div_table(mult_div_values**, int, int);
	void delete_table(mult_div_values **, int);

	void new_board();
	int check_rows(char**);
	int check_cols(char**);
