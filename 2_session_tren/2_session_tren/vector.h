#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>
typedef struct {
	int* data;
	size_t size;
	size_t capacity;
} Vector;

void vector_init(Vector* v, size_t initial_capacity);
void vector_destroy(Vector* v);
void vector_push_back(Vector* v, int value);
void process_vector(Vector* v);
void print_vector(Vector* v);
void set(Vector* v, int i, int val);
int get(Vector* v, int i);
void insert(Vector* v, int i, int value);
void erse(Vector* v, int i);

#endif
