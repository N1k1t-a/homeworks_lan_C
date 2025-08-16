#ifndef LINE_H
#define LINE_H


class Line {
private:
	int x1;
	int x2;
	int y1;
	int y2;

public:
	Line(int val_x1, int val_x2, int val_y1, int val_y2);

	void show();
	bool is_straight();
};

#endif