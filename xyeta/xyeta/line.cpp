#include "line.h"
#include <iostream>

Line::Line(int val_x1, int val_x2, int val_y1, int val_y2) {
	x1 = val_x1;
	x2 = val_x2;
	y1 = val_y1;
	y2 = val_y2;
}

void Line::show() {
	std::cout << " координаты первой точки: " << x1 << " " << y1 << std::endl;
	std::cout << " координаты второй точки: " << x2 << " " << y2 << std::endl;
}

bool Line::is_straight() {
	return (x1 == x2 or y1 == y2);
}