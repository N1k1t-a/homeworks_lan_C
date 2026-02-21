#include <iostream>
#include <string>

void aboba(int n, int k, std::string ab) {
	if (n == 0) {
		std::cout << ab << std::endl;
		return;
	}

	for (int i = k; i >= 1; i--) {
		if (i <= n) {
			std::string next;

			if (ab.empty()) {
				next = std::to_string(i);
			}
			else {
				next = ab + "+" + std::to_string(i);
			}
			aboba(n - i, i, next);
		}
	}
}

int main() {
	int n;
	std::cout << "Vvedite chislo: ";
	std::cin >> n;

	aboba(n, n, "");

	return 0;
}