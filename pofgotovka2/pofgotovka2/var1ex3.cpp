class Figure {
protected:
	int x;
	int y;

public:
	Figure(int x_val, int y_val) : x(x_val), y(y_val){}
};

class Rectangle : public Figure {
protected:
	int width;
	int height;

public: 
	Rectangle(int x_val, int y_val, int w, int h) : Figure(x_val, y_val), width(w), height(h) {}
};

class Figure {
protected: 
	int x; 
	int y;

public: 
	Figure(int val_x, int val_y) : x(val_x), y(val_y) {}

};


class Rectangle : public Figure {
protected:
	int weith;
	int height;

public:

	Rectangle(int val_x, int val_y, int w, int h) : Figure(val_x, val_y), weith(w), height(h) {}
};