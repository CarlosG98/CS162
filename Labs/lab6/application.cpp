#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include <iostream>
#include <string>

using namespace std;

int main(){


	Shape a1;
	Shape a2 = Shape("triangle", "green");

	cout << "a1 shape: " << a1.get_color() << " " << a1.get_name() << endl;

	cout << "a2 shape: " << a2.get_color() << " " << a2.get_name() << endl;

	Circle c1;

	cout << "c1 circle: " << c1.get_color() << " " << c1.get_name() << " " << c1.get_radius() << endl;
	cout << "c1 area: " << c1.area() << endl;

	Circle c2 = Circle(4, "Blue");
	cout << "c2 circle: " << c2.get_color() << " " << c2.get_name() << " " << c2.get_radius() << endl;
	cout << "c2 area: " << c2.area() << endl;
	
	Rectangle r1;

	cout << "r1 rectangle: " << r1.get_color() << " " << r1.get_name() << " " << r1.get_width() << " " << r1.get_height() << endl;
	cout << "r1 area: " << r1.area() << endl;

	Rectangle r2 = Rectangle(10, 2, "Red");
	cout << "r2 rectangle: " << r2.get_color() << " " << r2.get_name() << " " << r2.get_width() << " " << r2.get_height() << endl;
	cout << "r2 area: " << r2.area() << endl;
	

return 0;
}
