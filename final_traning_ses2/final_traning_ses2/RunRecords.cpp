#include "RunRecords.h"
#include <iostream>


RunRecords::RunRecords(int val_k) {
	kol_vo = val_k;

	ids = new int[kol_vo]();
	result = new int[kol_vo]();
}


RunRecords::~RunRecords() {
	delete[] ids;
	delete[] result;
}

void RunRecords::show() const {
	std::cout << "количество челиксов бегунков" << kol_vo << std::endl;

	for (int i = 0; i < kol_vo; i++) {
		std::cout << "чел по номером " << ids[i] << " у него такой вот результат" << result[i] << std::endl;
	}
}

int RunRecords::get(int n) const {
	std::cout << "у чела с номером" << n << " результат" << result[n];
	return result[n];
}