#include <vector>
#include <map>
#include <string>

std::string aboba(std::vector<std::string>& v) {

	std::map<std::string, int> aba;
	for (size_t i = 0; i < v.size(); i++) {
		aba[v[i]]++;
	}
	std::string aboba;
	int tmp = 0;

	for (size_t i = 0; i < v.size(); i++) {
		if (aba[v[i]] > tmp) {
			tmp = aba[v[i]];
			aboba = v[i];
		}
	}
	return aboba;
}


int returnal(std::vector<int>& v) {

	std::map<int, int> aboba;

	for (size_t i = 0; i < v.size(); i++)
		aboba[v[i]]++;

	int max_massenger = 0;
	int name_aboba;

	for (auto& xyi : aboba) {
		if (max_massenger < xyi.second) {
			max_massenger = xyi.second;
			name_aboba = xyi.first;
		}

	}
	return name_aboba;
}


std::map<char, int> abobas(std::vector<std::string>& v) {

	std::map<char, int> gooba;

	for (size_t i = 0; i < v.size(); i++) {
		gooba[v[i][0]]++;
	}
	return gooba;
}