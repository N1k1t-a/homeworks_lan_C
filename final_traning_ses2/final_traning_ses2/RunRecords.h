#ifndef RUNRECORDS_H
#define RUNRECORDS_H

class RunRecords {
private:
	int* ids;
	int* result;
	int kol_vo;

public:
	RunRecords(int val_k);

	~RunRecords();

	void show() const;
	int get(int n) const;
};

#endif