#include <stdexcept>

template <typename T>
void aboba(T* src1, T* src2, T* result, int src1_size, int src2_size, int result_size) {
	if (result_size < src1_size + src2_size)
		throw std::exception("Иди нахуй");

	for (size_t i = 0; i < src1_size; i++) {
		result[i] = src1[i];
	}

	for (size_t i = 0; i < src2_size; i++) {
		result[i + src1_size] = src2[i];
	}
}