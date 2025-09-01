#ifndef RUNRECORDS_H
#define RUNRECORDS_H


class RunRecords {
private:
	int* ids;
	int* result;
	int kol_vo;

public:
	RunRecords(int n);

	~RunRecords();

	void show();
	int get(int i);

};

void coppy_array_sqadis(int* array1, int* array2, int n);

#endif