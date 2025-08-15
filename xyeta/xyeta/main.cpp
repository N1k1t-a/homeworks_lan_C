#include "circle.h"
#include <iostream>

int main() {
	system("chcp 1251");
	Circle c1(0.0, 0.0, 5.0);
	c1.show();
	std::cout << "площадь круга" << c1.square() << std::endl;

	return 0;
}