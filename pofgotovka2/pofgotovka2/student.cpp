#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include <iostream>
#include <string.h>


Student::Student(char* val_name, int val_kol_vo) {
	strcpy(name, val_name);
	grades = new int[kol_vo];

}

Student::~Student() {
	delete[] grades;
}

void Student::show() {
	std::cout << name << std::endl;

	for (int i = 0; i < kol_vo; i++) {
		std::cout << grades[i] << "оценка эта за экзамен с айди " << i << std::endl;
	}
}

void Student::set(int i, int oc) {
	grades[i] = oc;
}