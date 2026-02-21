#include "Rectangle.h"
#include <iostream>

int* get_array_sum(int n) {
	int res = 0;

	for (int i = 1; i <= n; i++){
		std::cout << i << std::endl;
	res += i;
	}
	
	int* arr = new int[res];

	for (int i = 0; i < res; i++)
		arr[i] = 1;

	return arr;

}