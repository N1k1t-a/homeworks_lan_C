#include "line.h"
#include <iostream>

int* get_array_mul(int n, int m) {
	int size;
	if (n < m)
		size = m;
	else
		size = n;

	int* arr = new int[size];

	return arr;

}