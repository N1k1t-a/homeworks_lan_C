#include <vector>
#include <set>

int differentcount(std::vector<int>& v) {
	std::set<int> ab;

	for (size_t i = 0; i < v.size(); i++) {
		ab.insert(v[i]);
	}
	return ab.size();
}


bool aboba(std::vector<int>& b) {
	bool xyi = false;

	std::set<int> xyis(b.begin(), b.end());

	if (b.size() != xyis.size())
		xyi = true;

	return xyi;
}