

int xyi(Node* aboba) {
	if (aboba == nullptr)
		return 0;

	return 1 + xyi(aboba->left) + xyi(aboba->right)
}


int abobus(Node* aboba) {
	if (aboba == nullptr)
		return 0;

	
	return aboba->value + abobus(aboba->left) + abobus(aboba->right);
}

#include <algorithm>
int abob(Node* aboba) {
	if (aboba == nullptr)
		return 0;

	return 1 + std::max(aboba(abob->left), aboba(abob->right));
	
	
}