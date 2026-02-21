#include "circle.h"
#include <iostream>

Circle::Circle(double val_x, double val_y, double r) {
	x = val_x;
	y = val_y;
	radius = r;
}

void Circle::show() {
	std::cout << "координаты центра" << x << " " << y << std::endl;
	std::cout << "радиус:" << radius << std::endl;
}

double Circle::square() {
	double pi = 3.14;
	return pi * radius * radius;
}