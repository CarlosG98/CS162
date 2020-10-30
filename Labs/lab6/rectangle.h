#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "shape.h"
#include <string>

using namespace std;

class Rectangle : public Shape {
	private:
		float width;
		float height;
	public:
		Rectangle();
		Rectangle(string);
		Rectangle(float, float, string);
		float get_width();
		float get_height();
		void set_width(float);
		void set_height(float);
		float area();
		friend bool operator>(const Rectangle&, const Rectangle&);
		friend bool operator<(const Rectangle&, const Rectangle&);
};
#endif

