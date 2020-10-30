#include <iostream>
#include <ctime>
#include <cstdlib>
#include "cards.hpp"
#include "deck.hpp"

using namespace std;

int main(){
	
srand(time(NULL));
	deck d1;

	d1.create_deck();

	cout << "ORIGINAL DECK: " << endl;
	d1.print_deck();
	cout << endl;

	d1.shuffle();

	cout << "SHUFFLED DECK: " << endl;
	d1.print_deck();
	cout << endl;

return 0;
}
