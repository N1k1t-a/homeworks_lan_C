#include "student.h"
#include <iostream>

void set_array_squares(int array[], int n) {
	for (int i = 0; i < n; i++)
		array[i] = i * i;

	for (int i = 0; i < n; i++)
		std::cout << array[i] << " ";
}