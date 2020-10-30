#ifndef CARDS_H
#define CARDS_H

#include <iostream>


using namespace std;

class card{
private:
	char suit;
	int rank;
public:
	char get_suit() const;
	void set_suit(char);
	int get_rank() const;
	void set_rank(int);
};
#endif
