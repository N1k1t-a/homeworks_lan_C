

int xyi(Node* aboba) {
	if (aboba == nullptr)
		return 0;

	if (! aboba->left && !aboba->right) {
		return 1;
	}

	return xyi(aboba->left) + xyi(aboba->right);

}