struct Node {
	int value;
	Node* next;
};


class List {
private:
	Node* head;
public:
	List() {
		head = nullptr;
	}
	~List() {
		Node* current = head;

		while (current) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}

	void zamena() {
		if (head == nullptr) return;

		int first_val = head->value;

		Node* current = head->next;
		while (current) {
			current->value = first_val;
			current = current->next;
		}
	}
};	
