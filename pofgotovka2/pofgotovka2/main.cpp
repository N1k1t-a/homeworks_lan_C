#include "circle.h"
#include "line.h"
#include "Rectangle.h"
#include "equation.h"
#include "student.h"
#include "runrecords.h"
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


	std::cout << std::endl << std::endl << "это первое задание третьего варианта" << std::endl;

	Rectangle r1(1, 23, 4, 2);
	r1.show();

	std::cout << "это второе задание третьего варианта" << std::endl;

	int* a = get_array_sum(3);

	for (int i = 0; i < 6; i++) {
		std::cout << a[i] << " ";
	}

	std::cout << std::endl << std::endl << "это первое задание четвертого варианта" << std::endl;

	Equation eq1(2, 4, 2);

	eq1.has_roots();
	eq1.show();

	std::cout << "это второе задание четветого варианта" << std::endl;

	int* ress = get_array_avg(4, 6);

	for (int i = 0; i < 5; i++)
		std::cout << ress[i] << " ";

	std::cout << std::endl << std::endl << "это первое задание шестого варианта" << std::endl;

	std::cout << "обойдемся пожалуй без примера, потому что я умный и мне лень" << std::endl;
	
	const int n = 6;
	int array[n];

	set_array_squares(array, n);

	std::cout << "Это второе задание седьмого варианта " << std::endl;

	const int n2 = 8;
	int array1[n2];
	int array2[n2]{ 1, 2, 3, 4, 5, 6, 7, 8 };

	coppy_array_sqadis(array1, array2, n2);

	for (int i = 0; i < n2; ++i) {
		std::cout << array1[i] << "  ";
	}

	return 0;
}