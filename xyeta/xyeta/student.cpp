#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "student.h"


Student::Student(const char* name_val, int exams_v) {
	strcpy(name, name_val);
	exams = exams_v;
	grades = new int[exams];
	for (int i = 0; i < exams; i++) {
		grades[i] = 0;
	}
}
Student::~Student() {
	delete[]grades;
}
void Student::set(int index, int grade) {
	if (index >= 0 && index < exams) {
		grades[index] = grade;
	}
	else {
		std::cout << "error" << std::endl;
	}
}
void Student::show() const {
	std::cout << name << std::endl;
	for (int i = 0; i < exams; i++) {
		std::cout << grades[i] << std::endl;
	}
}
