#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(int val_x, int val_y, int val_d1, int val_d2) {
	x = val_x;
	y = val_y;
	d1 = val_d1;
	d2 = val_d2;
}

void Rectangle::show() const {
	std::cout << "начальная левая точка " << x << " " << y << std::endl;
	
	std::cout << "первая сторона " << d1 << "вторая сторона " << d2;
}

int Rectangle::perimentr() const {
	return (d1 + d2) * 2;
}