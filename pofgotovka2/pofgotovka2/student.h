#ifndef STUDENT_H
#define STUDENT_H

class Student {
private:
	char name[100];
	int* grades;
	int kol_vo;
public:
	Student(char* val_name, int val_kol_vo);

	~Student();

	void show();
	void set(int i, int oc);
};

void set_array_squares(int array[], int n);

#endif
