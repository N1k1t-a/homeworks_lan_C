#include "circle.h"
#include "line.h"
#include "Rectangle.h"
#include "Equation.h"
#include <iostream>

int main() {
	system("chcp 1251");
	Circle c1(0.0, 0.0, 5.0);
	c1.show();
	std::cout << "площадь круга" << c1.square() << std::endl;

	int* array = get_array_pow(5, 2);

	int size = 5 * 5;

	for (int i = 0; i < size; i++) {
		std::cout << array[i];
	}

	std::cout << std::endl;

	Line line1(2, 2, 12, 1);

	if (line1.is_straight()){
		std::cout << "прямая" << std::endl;
	}

	Rectangle r1(0, 0, 12, 4);
	r1.show();
	std::cout << r1.perimeter() << "ето периметр" << std::endl;

	int* aboba = get_array_sum(3);

	for (int i = 0; i < 6; i++) {
		std::cout << aboba[i];
	}
	std::cout << std::endl;


	Equation eq1(1, 2, 1);
	eq1.has_roots();

	std::cout << std::endl;

	int* max = get_array_avg(3, 5);

	for (int i = 0; i < 4; i++)
		std::cout << max[i];


	return 0;
}