#include "equation.h"
#include <iostream>
#include <cmath>


Equation::Equation(int val_a, int val_b, int val_c) {
	a = val_a;
	b = val_b;
	c = val_c;
}

void Equation::show() {
	std::cout << a << "x^2 + " << b << "* x + " << c << std::endl;
}

void Equation::has_roots() {
	if (a == 0) {
		std::cout << "gg";
		return;
	}

	int D = b * b - 4 * a * c;

	if (D > 0) {
		double x1 = (-b + sqrt(D)) / (2 * a);
		double x2 = (-b - sqrt(D)) / (2 * a);
		std::cout << "первый корень: " << x1 << std::endl;
		std::cout << "второй корень: " << x2 << std::endl;
	}

	if (D == 0) {
		double x = -b / (2 * a);
		std::cout << "корень: " << x << std::endl;

	}
}