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

#endif