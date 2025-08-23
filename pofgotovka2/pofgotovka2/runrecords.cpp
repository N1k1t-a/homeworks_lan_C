#include "runrecords.h"
#include <iostream>


RunRecords::RunRecords(int n) {
	ids = new int[n];
	result = new int[n];
	kol_vo = n;

	for (int i = 0; i < n; i++) {
		ids[i] = 0;
		result[i] = 0;
	}
}

RunRecords::~RunRecords() {
	delete[] ids;
	delete[] result;
}

void RunRecords::show() {

}

int RunRecords::get(int i) {
	return result[i];
}