#pragma once

#include <stdlib.h>

typedef struct {
	char* name;
	int age;
} Person;


void universal_merge_sort(void* array, int count, size_t size, int (*compare)(const void*, const void*));
size_t universal_bubble_sort(void* array, int count, size_t size,
	int (*compare)(const void*, const void*));

size_t universal_selection_sort(void* array, int count, size_t size,
	int (*compare)(const void*, const void*));

size_t universal_insertion_sort(void* array, int count, size_t size,
	int (*compare)(const void*, const void*));

size_t universal_shell_sort(void* array, int count, size_t size,
	int (*compare)(const void*, const void*));
size_t universal_quick_sort(void* array, int count, size_t size, int (*compare)(const void*, const void*));
size_t universal_heap_sort(void* array, int count, size_t size,
	int (*compare)(const void*, const void*));

int compare_int(const void* a, const void* b);
int compare_person(const void* a, const void* b);

void read_sorting_input(const char* filename, int** int_array, int* int_count,
	Person** person_array, int* person_count);
void write_sorting_output(const char* filename, int* int_array, int int_count,
	Person* person_array, int person_count);

void free_person_array(Person* array, int count);