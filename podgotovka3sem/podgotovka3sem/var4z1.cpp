#include <stdexcept>


template <typename T>
void copy_longer(T* src1, int size1, T* src2, int size2, T* result, int result_size) {
	
	if (size1 >= size2) {
		if (result_size < size1)
			throw std::exception("знай, не все потеряно пока");
		for (size_t i = 0; i < size1; i++)
			result[i] = src1[i];
	}
	else {
		if (result_size < size2)
			throw std::exception("знай, не все потеряно пока");
		for (size_t i = 0; i < size2; i++)
			result[i] = src2[i];
	}

}



template <typename T>
void aboba(T* src1, T* src2, T* result, int src2_size, int src1_size, int result_size) {

	int counter1 = 0;
	int counter2 = 0;

	for (size_t i = 0; i < src1_size; i++) {
		counter1 += src1[i];
	}
	for (size_t i = 0; i < src2_size; i++) {
		counter2 += src2[i];
	}

	if (counter1 < counter2) {
		if (src1_size > result_size)
			throw std::exception("xyi");
		for (size_t i = 0; i < src1_size; i++) {
			result[i] = src1[i];
		}
	}

	if (counter2 <= counter1) {
		if (src2_size > result_size)
			throw std::exception("sosi jopy");
		for (size_t i = 0; i < src2_size; i++)
			result[i] = src2[i];
	}
}