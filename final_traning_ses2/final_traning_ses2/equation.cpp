#include "equation.h"
#include <iostream>
#include <cmath>

Equation::Equation(int val_a, int val_b, int val_c) {
	a = val_a;
	b = val_b;
	c = val_c;
}


void Equation::show() const {
	std::cout << "x^2" << " *" << a << "+" << "x*" << b << " +" << c << std::endl;
}

void Equation::korny() const{
	double d = b * b - (4 * a * c);

	if (d < 0)
		return;

	if (d == 0)
		std::cout << -b / (2 * a);
	else {
		double x1 = (-b + std::sqrt(d)) / (2 * a);
		double x2 = (-b - std::sqrt(d)) / (2 * a);
		std::cout << x1 << std::endl;
		std::cout << x2 << std::endl;
	}
}