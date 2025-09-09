#ifndef LINE_H
#define LINE_H

class Line {
private:
	int x1;
	int x2;
	int y2;
	int y1;

public:
	Line(int val_x1, int val_x2, int val_y2, int val_y1);

	void show() const;
	int is_straight() const;
};

#endif