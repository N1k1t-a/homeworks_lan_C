#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void init(list_t* l) {
	l->head = NULL;
	l->size = 0;
}

void destroy(list_t* l) {
	Node* cur = l->head;
	while (cur != NULL) {
		Node* next = cur->next;  // запомним следующий узел
		free(cur);               // освободим память текущего
		cur = next;              // перейдём к следующему
	}
}