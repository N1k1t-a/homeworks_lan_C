#include "circle.h"
#include "line.h"
#include <iostream>


int main() {
	system("chcp 1251");
	Circle c1(0, 0, 5.0);

	c1.show();
	std::cout << c1.square() << " абобa" << std::endl;

	std::cout << "это первое задание первого варианта" << std::endl;
	
	std::cout << "это второе задание первого варианта" << std::endl;

	int* res = get_array_pow(2, 3);
	for (int i = 0; i < 8; i++) {
		std::cout << res[i] << " ";
	}

	std::cout << std::endl << std::endl << "это первое задание второго варианта" << std::endl;

	Line le1(2, 2, 1, 3);

	le1.show();
	int i = le1.is_straight();

	std::cout << i << std::endl;

	return 0;
}