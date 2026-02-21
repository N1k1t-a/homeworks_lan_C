#include <list>

void aboba(std::list<int>& v) {
	for (auto i = v.begin(); i != v.end(); ) {
		if ((*i % 2 != 0)) {
			i = v.erase(i);
		}
		else
			i++;
	}
}


void abobus(std::list<int>& v) {
	for (auto i = v.begin(); i != v.end(); i++)
		*i *= 2;
}


void yaeblan(std::list<int>& l) {
	for (auto i = l.begin(); i != l.end(); ) {
		if (*i > 10) {
			i = l.erase(i);
		}
		else
			i++;
	}
}


void claude_ya_eblan(std::list<int>& l) {
	for (auto i = l.begin(); i != l.end(); ) {
		if (*i % 2 == 0) {
			i++;
			l.insert(i, 0);
		}
		else
			i++;
	}
	
}