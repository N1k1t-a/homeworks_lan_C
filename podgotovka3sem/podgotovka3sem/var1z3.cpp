#include <string>
#include <iostream>

void generate(std::string my_str, int n, int m) {
	if (n == 0 && m == 0) {
		std::cout << my_str << std::endl;
	}

	else {
		if (n > 0) {
			for (char i = 'A'; i <= 'Z'; i++)
				generate(my_str + i, n - 1, m);
		}
		else if (m > 0) {
			for (char i = '0'; i <= '9'; i++)
				generate(my_str + i, n, m-1);
		}
	}
}



void aboba(std::string a, int n) {
	if (n == 0)
		std::cout << a << std::endl;


	else {
		for (char i = '0'; i <= '1'; i++)
			aboba(a + i, n - 1);
	}
}

void password(std::string a, int kol_str, int sumv) {
	if (kol_str == 0 && sumv == 0) {
		std::cout << a << std::endl;
	}

	else {
		if (kol_str > 0) {
			for (char i = 'a'; i <= 'z'; i++) {
				password(a + i, kol_str - 1, sumv);
			}
		}
		else if (sumv > 0) {
			std::string spez = "!@#";
			for (size_t i = 0; i < spez.size(); i++) {
				password(a + spez[i], kol_str, sumv - 1);
			}
		}
	}
}

int main() {
	aboba("", 5);  // много вывода
	// или сделай свой алфавит покороче для теста
	return 0;
}