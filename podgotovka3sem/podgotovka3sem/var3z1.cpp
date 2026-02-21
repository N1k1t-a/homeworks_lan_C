#include <vector>



void vstavka(std::vector<int>& v, int before, int after) {
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i] == before) {
			v.insert(v.begin() + i + 1, after);
			i++;
		}
	}
}


void remove_all(std::vector<int>& b, int value) {
	for (size_t i = 0; i < b.size(); i++) {
		if (b[i] == value) {
			b.erase(b.begin() + i);
			i--;
		}
	}
 }




void duplicate_even(std::vector<int>& aboba) {
	for (size_t i = 0; i < aboba.size(); i++) {
		if (aboba[i] % 2 == 0) {
			aboba.insert(aboba.begin() + i + 1, aboba[i]);
			i++;
		}
	}
}



std::vector<int> merge_sorted(std::vector<int>& a, std::vector<int>& b) {
	int x = 0;
	int y = 0;

	std::vector<int> aboba;

	size_t xyi = a.size() + b.size();
	
	for (size_t i = 0; i < xyi; i++) {
		if (x < a.size() && y < b.size()) {
			if (a[x] < b[y]) {
				aboba.push_back(a[x]);
				x++;
			}
			else {
				aboba.push_back(b[y]);
				y++;
			}
		}
		else if (x < a.size()) {
			aboba.push_back(a[x]);
			x++;
		}
		else if (y < b.size()) {
			aboba.push_back(b[y]);
			y++;
		}
	}

	return aboba;

}


int aboba(std::vector<int>& a, int target) {
	int counter = 0;
	for (size_t i = 0; i < a.size(); i++) {
		if (a[i] == target) {
			a.erase(a.begin() + i);
			i--;
			counter++;
		}
	}
	return counter;
}