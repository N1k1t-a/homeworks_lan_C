class Pere {
private:
	int a;
	int b;
public:
	Pere(int val_a, int val_b) {
		a = val_a;
		b = val_b;
	}

	bool operator==(const Pere& other)const {
		return a == other.a && b == other.b;
	}
};

