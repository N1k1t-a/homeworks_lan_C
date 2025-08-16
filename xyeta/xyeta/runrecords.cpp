#include "runrecords.h"
#include <iostream>


RunRecords::RunRecords(int kol) {
	kol_vo = kol;
	ids = new int[kol_vo];
	result = new int[kol_vo];
}

RunRecords::~RunRecords() {
	delete[]ids;
	delete[]result;

}

void RunRecords::show() {
	std::cout << "всего спортиков" << kol_vo << std::endl;

	for (int i = 0; i < kol_vo; i++)
		std::cout << "спортсмен номер: " << ids[i] << "результат" << result[i] << std::endl;
}

void RunRecords::set(int nomer_sport, int result_sport) {
	ids[nomer_sport] = nomer_sport;
	result[nomer_sport] = result_sport;
}

int RunRecords::get(int i) {
	int nomer = i + 1;

	std::cout << "результат спортсмена номер" << result[nomer];

	return result[nomer];
}