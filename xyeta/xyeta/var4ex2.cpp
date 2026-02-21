#include "Equation.h"
#include <iostream>


int* get_array_avg(int m, int n) {
	int avg = (m + n) / 2;

	int* arr = new int[avg];

	for (int i = 0; i < avg; i++) {
		arr[i] = 0;
	}

	return arr;
}