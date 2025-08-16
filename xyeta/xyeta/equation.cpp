#include "Equation.h"
#include <iostream>
#include <cmath>


Equation::Equation(int val_a, int val_b, int val_c) {
	a = val_a;
	b = val_b;
	c = val_c;
}


void Equation::show() {
	std::cout << a << "x^2 + " << b << "x + " << c << std::endl;
}

void Equation::has_roots() {

	double D = b*b - 4 * a * c;

	if (a == 0){
		std::cout << "gg" << std::endl;
		return;
	}

	if (D > 0) {
		double x1 = (-b + std::sqrt(D)) / (2 * a);
		double x2 = (-b - std::sqrt(D)) / (2 * a);
		std::cout << "x1 = " << x1 << "x2 = " << x2 << std::endl;
	}

	else if (D == 0) {
		double x = (-b) / (2 * a);
		std::cout << "x = " << x << std::endl;
	}
}
