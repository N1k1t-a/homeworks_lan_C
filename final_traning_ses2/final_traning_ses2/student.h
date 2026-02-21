#ifndef STUDENT_H
#define STUDENT_H

class Student {
private:
	char name[100];
	int* grades;
	int kol_vo;
public:

	Student(char name_v[], int val_k);

	~Student();

	void show() const;
	void set(int index, int grade);
		
};

#endif