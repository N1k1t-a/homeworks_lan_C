#include "equation.h"


int* get_array_avg(int n, int m) {
	int avg = (n + m) / 2;

	int* arr = new int[avg];

	for (int i = 0; i < avg; i++) {
		arr[i] = 0;
	}

	return arr;
}