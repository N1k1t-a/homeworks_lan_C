#include <stdexcept>
#include <iostream>

template <typename T>
void delenie_array(T* src1, T* src2, int n) {
	for (size_t i = 0; i < n; i++) {
		if (src2[i] == 0) {
			throw std::exception("≈бать клауде крутой");
		}
		else
			std::cout << src1[i] / src2[i] << std::endl;
	}
}


template <typename T>
void aboba(T* src1, T* src2, int n) {
	for (size_t i = 0; i < n; i++) {
		if (src2[i] == 0)
			throw std::exception("нельз€ делить на ноль");
		std::cout << src1[i] % src2[i] << std::endl;
	}
}