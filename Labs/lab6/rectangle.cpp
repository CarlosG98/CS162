#include "rectangle.h"
#include "shape.h"

#include <iostream>
#include <string>

using namespace std;

Rectangle::Rectangle() : Shape("rectangle", "Unknown Color"){
	width = 0;
	height = 0;
}

Rectangle::Rectangle(float w, float h, string color) : Shape("rectangle", color){
	width = w;
	height = h;
}

float Rectangle::get_width(){
	return width;
}

float Rectangle::get_height(){
	return height;
}

void Rectangle::set_width(float w){
	width = w;
}

void Rectangle::set_height(float h){
	height = h;
}

float Rectangle::area(){
	float area = width * height;
	return area;
}

bool operator>(const Rectangle&r1, const Rectangle& r2){
	return (r1.height*r1.width) > (r2.height*r2.width);
}


