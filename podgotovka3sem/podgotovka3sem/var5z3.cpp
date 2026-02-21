

void aboba(Node* ab) {
	if (ab->childs.size() == 3)
		std::cout << ab->val  << std::endl;


	for (size_t i = 0; i < ab->childs.size(); i++) {
		aboba(&ab->childs[i]);
	}
}