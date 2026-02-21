#include <stdexcept>

template <typename T>
void aboba(T* src, size_t size) {
	for (size_t i = 0; i < size; i++) {
		try {
			src[i] = f(src[i]);
		}
		catch (std::exception e) {
			src[i] = 0;
		}
	}
}


template <typename T>
void aboba(T* src, int size, T defaultValue) {

	for (size_t i = 0; i < size; i++) {
		try {
			src[i] = g(src[i]);
		}
		catch (std::exception) {
			src[i] = defaultValue;
		}
	}
}