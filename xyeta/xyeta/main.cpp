#include "circle.h"
#include "line.h"
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
		std::cout << "прямая";
	}



	return 0;
}