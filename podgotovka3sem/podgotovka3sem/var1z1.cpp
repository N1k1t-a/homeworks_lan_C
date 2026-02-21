#include <stdexcept>
#include <vector>

template <typename T>
void max_arrays(T* src1, T* src2, int src1_size, int src2_size) {
	if (src1_size != src2_size) {
		throw std::exception("Длинны не равны");
	}

	for (size_t i = 0; i < src1_size; i++) {
		if (src1[i] > src2[i])
			src2[i] = src1[i];
	}
}


template <typename T>
T* sum_arrays(T* src1, T* src2, int src1_size, int src2_size) {
	if (src1_size != src2_size)
		throw std::exception("Длинны не совпадают");

	T* src3 = new T[src1_size];

	for (size_t i = 0; i < src1_size; i++) {
		src3[i] = src1[i] + src2[i];
	}
	return src3;
		
}



template <typename T>
void copy_if_positive(T* src, T* dest, int n) {
	if (n == 0) {
		throw std::exception("ВСе хуево");
	}

	for (size_t i = 0; i < n; i++) {
		if (src[i] > 0)
			dest[i] = src[i];
		else
			dest[i] = 0;
	}

}


template <typename T>
int count_in_range(T* arr, int n, T min_val, T max_val) {
	if (min_val > max_val) {
		throw std::exception("Теперь точно пизда");
	}
	
	int counter = 0;

	for (size_t i = 0; i < n; i++) {
		if (arr[i] >= min_val && arr[i] <= max_val)
			counter++;
	}
	return counter;
}



template <typename T>
T* xyaynt_in_range(T* arr, int n, T min_val, T max_val) {
	if (min_val > max_val) {
		throw std::exception("Теперь точно пизда");
	}

	int counter = 0;

	for (size_t i = 0; i < n; i++) {
		if (arr[i] >= min_val && arr[i] <= max_val)
			counter++;
	}

	T* aboba = new T[counter];

	int j = 0;
	for (size_t i = 0; i < n; i++) {
		if (arr[i] >= min_val && arr[i] <= max_val)
			aboba[j++] = arr[i];
	}
	return aboba;
}



template <typename T>
int sum_array(T* src1, T* src2, int size1, int size2) {
	if (size1 != size2) {
		throw std::exception("ну как так вася");
	}

	int summa = 0;

	for (size_t i = 0; i < size1; i++) {
		if (src1[i] < src2[i])
			summa += src1[i];
		else
			summa += src2[i];

	}
	return summa;
}