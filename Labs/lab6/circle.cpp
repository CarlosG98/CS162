#include "circle.h"
#include "shape.h"
#include <string>
#include <iostream>

using namespace std;

Circle::Circle() : Shape("circle", "Unknown Color") {
	this->radius = 0;
}

Circle::Circle(float r, string color) : Shape("circle", color){
	this->radius = r;
}

float Circle::get_radius(){
	return radius;
}

void Circle::set_radius(float r){
	this->radius = r;
}

float Circle::area(){
	const double pi = 3.14159265358979323846;
	float area = 2 * pi * radius * radius;
	return area;
}
