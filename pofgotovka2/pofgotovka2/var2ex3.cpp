#include <iostream>

class Vector {
private:
	int* arr;
	size_t size;

public:
	Vector(size_t n) {
		size = n;

		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = i;
		
	}
	~Vector() {
		delete[] arr;
	}

	void show() {
		for (int i = 1; i < size; i += 2) {
			std::cout << arr[i] << std::endl;
		}
	}
};