#ifndef CIRCLE_H
#define CIRCLE_H


class Circle {
private:
	int x, y;
	double roudius;

public:
	Circle(int val_x, int val_y, double val_roud);

	void show();
	double  square();
};

int* get_array_pow(int n, int p);

#endif