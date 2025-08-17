#include "circle.h"
#include <iostream>

Circle::Circle(int val_x, int val_y, double val_roud) {
	x = val_x;
	y = val_y;
	roudius = val_roud;
}

void Circle::show() {
	std::cout << "Circle: (" << x << ", " << y << "), Radius: " << roudius << std::endl;
}


double Circle::square() {
	double pi = 3.14159265358979323846;
	return pi * roudius * roudius;
}