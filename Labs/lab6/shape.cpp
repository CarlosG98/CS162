#include "shape.h"
#include <iostream>
#include <string>

using namespace std;

Shape::Shape(){
	name = "Unknown Shape";
	color = "Unknown Color";
}

Shape::Shape(string n, string c){
	name = n;
	color = c;
}

string Shape::get_name(){
	return name;
}

string Shape::get_color(){
	return color;
}

void Shape::set_name(string n){
	name = n;
}

void Shape::set_color(string c){
	color = c;
}

int Shape::area(){
	return 0;
}
