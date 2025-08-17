#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(int val_x, int val_y, int val_d1, int val_d2) {
	x = val_x;
	y = val_y;
	d1 = val_d1;
	d2 = val_d2;
}


void Rectangle::show() {
	std::cout << "начальные координаты" << x << " " << y << std::endl;
	std::cout << "диаметры" << d1 << " " << d2 << std::endl;
	std::cout << "периметр йоу" << perimetr() << std::endl;
}


int Rectangle::perimetr(){
	return (d1 + d2) * 2;
}