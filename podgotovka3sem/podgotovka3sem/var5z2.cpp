#include <list>
#include <set>
#include <string>


int aboba(std::list<std::string>& l) {
	std::set<std::string> abobus;

	for (auto i = l.begin(); i != l.end(); i++) {
		abobus.insert(*i);
	}

	return abobus.size();
} 