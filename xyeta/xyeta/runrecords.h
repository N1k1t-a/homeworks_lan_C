#ifndef RUNRECORDS_H
#define RUNRECORDS_H

class RunRecords {
private:
	int* ids;
	int* result;
	int kol_vo;

public:
	RunRecords(int kol);
	~RunRecords();


	void set(int nomer_sport, int result_sport);

	void show();
	int get(int i);

};

#endif