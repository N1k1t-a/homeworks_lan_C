#ifndef RELATED_LIST
#define RELATED_LIST


typedef struct Node {
	int value;
	struct Node* next;
	struct Node* prev;
} Node;

typedef struct list_t {
	Node* head;
	size_t size;
} list_t;



void init(list_t* l);
void destroy(list_t* l);

#endif