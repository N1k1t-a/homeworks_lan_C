#ifndef EQUATION_H
#define EQUATION_H

class Equation {
private:
	int a;
	int b;
	int c;

public:
	Equation(int val_a, int val_b, int val_c);

	void show() const;
	void korny() const;

};

#endif

