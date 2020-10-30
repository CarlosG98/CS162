#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>


using namespace std;

class Shape {
	private:
		string name;
		string color;
	public:
		Shape();
		Shape(string, string);
		string get_name();
		string get_color();
		void set_name(string);
		void set_color(string);
		int area();
};
#endif
