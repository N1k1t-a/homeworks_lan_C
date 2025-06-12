#include "vector.h"
#include <stdio.h>
#include <stdlib.h>


void vector_init(Vector* v, size_t initial_capacity) {
	v->data = malloc(initial_capacity * sizeof(int));
	if (v->data == NULL) exit(1);
	v->size = 0;
	v->capacity = initial_capacity;
}

void vector_destroy(Vector* v) {
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}

void vector_push_back(Vector* v, int value) {
	if (v->size == v->capacity) {
		v->capacity = (v->capacity == 0) ? 1 : v->capacity * 2;
		int* tmp = realloc(v->data, v->capacity * sizeof(int));
		if (tmp == NULL) {
			vector_destroy(v);
			exit(1);
		}
		v->data = tmp;
	}
	v->data[v->size++] = value;
}

void process_vector(Vector* v) {
	for (size_t i = 0; i < v->size; i++) {
		v->data[i] *= 2;
	}
}

void print_vector(Vector* v) {
	for (size_t i = 0; i < v->size; i++) {
		printf("%d\n", v->data[i]);
	}
}

void set(Vector* v, int i, int val) {
	if (!(i < 0 || i <= v->size))
		v->data[i] = val;

	else {
		printf("Index out of bounds\n");
	}
}

int get(Vector* v, int i) {
	if (!(i < 0 || i >= v->size)) 
		return v->data[i];

	else {
		printf("Index out of bounds\n");
	}
}

void insert(Vector* v, int i, int value) {
	int j = 0;
	vector_push_back(&v, 0); // Ensure there's space for the new element

	for (j = v->size - 1; j > i; j--) {
		v->data[j] = v->data[j - 1];
	}
	v->data[i] = value;
	v->size++;
}



void erse(Vector* v, int i) {
	if (i >= 0 && i < v->size) {
		for (int j = i; j < v->size - 1; j++) {
			v->data[j] = v->data[j + 1];
		}
		v->size--; // Уменьшаем размер вектора
	} 
	else {
		printf("Index out of bounds\n");
		exit(1);
	}
}

