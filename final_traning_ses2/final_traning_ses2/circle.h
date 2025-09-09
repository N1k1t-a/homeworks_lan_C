#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
	double x;
	double y;
	double radius;

public:
	Circle(double val_x, double val_y, double val_r);

	void show() const;
	double square() const;

};

#endif