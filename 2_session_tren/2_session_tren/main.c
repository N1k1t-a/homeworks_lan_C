#include "vector.h"
#include <stdio.h>

int main() {
    Vector v;
    vector_init(&v, 4);
    vector_push_back(&v, 10);
    vector_push_back(&v, 20);
    vector_push_back(&v, 20);
    vector_push_back(&v, 20);
    vector_push_back(&v, 20);
    vector_push_back(&v, 20);
    vector_push_back(&v, 20);
    vector_push_back(&v, 20);
    process_vector(&v);
    int get_vector = get(&v, 4);
    printf("%d\n\n", get_vector);
    set(&v, 4, 10000);
    set(&v, 100, 10000);
    set(&v, 7, 666);
    print_vector(&v);
    erse(&v, 7);
    print_vector(&v);
    vector_destroy(&v);
	printf("\n");

    return 0;
}
