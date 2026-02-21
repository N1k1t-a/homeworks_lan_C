#include "student.h"
#include <iostream>
#include <string.h>

Student::Student(char name_v[], int val_k) {
	strcpy(name, name_v);
	kol_vo = val_k;
	grades = new int[val_k]();
}

Student::~Student(){
	delete[] grades;
}

void Student::show() const{
	std::cout << kol_vo << "это количество экзаменов" << std::endl;
	for (int i = 0; i < kol_vo; i++) {
		std::cout << "на экзамени по индексу " << i << " оценка " << grades[i] << "   ";
	}

}

void Student::set(int index, int grade) {
	grades[index] = grade;
}