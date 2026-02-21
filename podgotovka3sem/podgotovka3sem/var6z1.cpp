#include <stdexcept>

template <typename T>
void aboba(T* src, int n) {
	for (size_t i = 0; i < n; i++) {
		try {
			src[i] = f(src[i]);
		}
		catch (const std::exception& e) {
			throw std::runtime_error("υσι");
		}
	}
	
}


template <typename T>
void aboba(T* src, int n) {
	for (int i = 0; i < n; i++) {
		try {
			src[i] = f(src[i]);
		}
		catch (const std::exception& e) {
			std::runtime_error re(e.what());
			std::cout << re.what() << std::endl;
		}
	}
}