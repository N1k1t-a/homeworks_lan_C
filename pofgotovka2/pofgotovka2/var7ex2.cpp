#include "runrecords.h"
#include <iostream>


void coppy_array_sqadis(int* array1, int* array2, int n) {
	for (int i = 0; i < n; i++) {
		array1[i] = array2[i] * array2[i];
	}
}