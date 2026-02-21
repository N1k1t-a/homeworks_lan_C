#ifndef STUDENT_H
#define STUDENT_H


class Student {
private:
	char name[100];
	int* grades;
	int exams;
public:
	Student(const char* name_val, int exams);
	~Student();

	void set(int index, int grade);
	void show()const;


};

#endif