#include "line.h"
#include <iostream>


Line::Line(int val_x1, int val_x2, int val_y1, int val_y2) {
	x1 = val_x1;
	x2 = val_x2;
	y1 = val_y1;
	y2 = val_y2;
}

void Line::show() {
	std::cout << "начальные коорлдинаты: " << x1 << " " << y1 << std::endl;
	std::cout << "конечные коорлдинаты: " << x2 << " " << y2 << std::endl;
}

int Line::is_straight() {
	if (x1 == x2 || y1 == y2)
		return 1;
	else return 0;

}