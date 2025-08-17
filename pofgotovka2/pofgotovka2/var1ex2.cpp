#include "circle.h"
#include <iostream>


int* get_array_pow(int n, int p) {
	int res = 1;

	for (int i = 0; i < p; i++) {
		res *= n;
	}

	int* arr = new int[res];

	for (int i = 0; i < res; i++) {
		arr[i] = 1;
	}

	return arr;
}

