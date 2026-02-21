#ifndef EQUATION_H
#define EQUATION_H


class Equation {
private:
	int a, b, c;

public:
	Equation(int val_a, int val_b, int val_c);
	
	void show();
	
	void has_roots();
};


int* get_array_avg(int m, int n);

#endif