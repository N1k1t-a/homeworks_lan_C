#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
	int x;
	int y;
	int d1;
	int d2;
public:
	Rectangle(int val_x, int val_y, int val_d1, int val_d2);

	void show() const;
	int perimentr() const;
};

#endif