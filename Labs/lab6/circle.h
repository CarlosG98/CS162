#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "shape.h"

class Circle : public Shape {
	private:
		float radius;
	public:
		Circle();
		Circle(float, string);
		float get_radius();
		void set_radius(float);
		float area();
};
#endif
