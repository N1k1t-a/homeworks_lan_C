#include "circle.h"
#include <iostream>

Circle::Circle(double val_x, double val_y, double val_r) {
	x = val_x;
	y = val_y;
	radius = val_r;
}

void Circle::show() const{
	std::cout << x << " y " << y << " radius " << radius << std::endl;

	std::cout << "площадь " << square();
}


double Circle::square() const{
	double pi = 3.14;

	return pi * radius * radius;
}