#include <iostream>

int* get_array_mul(int n, int m) {
	int res;
	if (n > m)
		res = n;
	else
		res = m;

	int* arr = new int[res];

	return arr;
}