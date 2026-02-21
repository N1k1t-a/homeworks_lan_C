#define _CRT_SECURE_NO_WARNINGS
#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare_int(const void* a, const void* b) {
    int int_a = *(const int*)a;
    int int_b = *(const int*)b;

    if (int_a < int_b) return -1; 
    if (int_a > int_b) return 1;  
    return 0;
}

int compare_person(const void* a, const void* b) {
    const Person* p1 = (const Person*)a;
    const Person* p2 = (const Person*)b;

    const char* n1 = (p1 && p1->name) ? p1->name : "";
    const char* n2 = (p2 && p2->name) ? p2->name : "";

    int name_cmp = strcmp(n1, n2);
    if (name_cmp != 0) return name_cmp;

    if (p1->age < p2->age) return -1;
    if (p1->age > p2->age) return 1;
    return 0;
}


static void merge(void* array, int left, int mid, int right,
                  size_t element_size, int (*compare)(const void*, const void*)) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    char* L = (char*)malloc(n1 * element_size);
    char* R = (char*)malloc(n2 * element_size);

    if (L == NULL || R == NULL) {
        free(L);
        free(R);
        return;
    }

    char* arr = (char*)array;

    for (int i = 0; i < n1; i++)
        memcpy(L + i * element_size, arr + (left + i) * element_size, element_size);
    for (int j = 0; j < n2; j++)
        memcpy(R + j * element_size, arr + (mid + 1 + j) * element_size, element_size);

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (compare(L + i * element_size, R + j * element_size) <= 0) {
            memcpy(arr + k * element_size, L + i * element_size, element_size);
            i++;
        } else {
            memcpy(arr + k * element_size, R + j * element_size, element_size);
            j++;
        }
        k++;
    }

    while (i < n1) {
        memcpy(arr + k * element_size, L + i * element_size, element_size);
        i++;
        k++;
    }

    while (j < n2) {
        memcpy(arr + k * element_size, R + j * element_size, element_size);
        j++;
        k++;
    }

    free(L);
    free(R);
}

static void merge_sort(void* array, int left, int right,
                       size_t element_size, int (*compare)(const void*, const void*)) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(array, left, mid, element_size, compare);

        merge_sort(array, mid + 1, right, element_size, compare);

        merge(array, left, mid, right, element_size, compare);
    }
}


void universal_merge_sort(void* array, int count, size_t size,
                          int (*compare)(const void*, const void*)) {
    if (count > 0 && array != NULL) {
        merge_sort(array, 0, count - 1, size, compare);
    }
}


void read_sorting_input(const char* filename, int** int_array, int* int_count,
                        Person** person_array, int* person_count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Oshibka otkrytiya faila %s\n", filename);
        exit(1);
    }

    int int_capacity = 10;
    int person_capacity = 10;

    *int_array = (int*)malloc(int_capacity * sizeof(int));
    *person_array = (Person*)malloc(person_capacity * sizeof(Person));

    if (*int_array == NULL || *person_array == NULL) {
        printf("Oshibka vydeleniya pamyati\n");
        fclose(file);
        exit(1);
    }

    *int_count = 0;
    *person_count = 0;

    char line[1024];
    int section = 0;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;

        if (strlen(line) == 0) continue;

        if (strstr(line, "CELYE CHISLA") != NULL) {
            section = 1;
            continue;
        } else if (strstr(line, "STRUCT PERSON") != NULL) {
            section = 2;
            continue;
        }

        switch (section) {
            case 1: {
                char* token = strtok(line, " \t");
                while (token) {
                    if (*int_count >= int_capacity) {
                        int_capacity *= 2;
                        int* temp = (int*)realloc(*int_array, int_capacity * sizeof(int));
                        if (temp == NULL) {
                            printf("Oshibka rasshireniya massiva\n");
                            fclose(file);
                            exit(1);
                        }
                        *int_array = temp;
                    }
                    (*int_array)[(*int_count)++] = atoi(token);
                    token = strtok(NULL, " \t");
                }
                break;
            }
            case 2: {
                char name[256];
                int age;
                if (sscanf(line, "%255s %d", name, &age) == 2) {
                    if (*person_count >= person_capacity) {
                        person_capacity *= 2;
                        Person* temp = (Person*)realloc(*person_array,
                                                         person_capacity * sizeof(Person));
                        if (temp == NULL) {
                            printf("Oshibka rasshireniya massiva\n");
                            fclose(file);
                            exit(1);
                        }
                        *person_array = temp;
                    }
                    (*person_array)[*person_count].name = (char*)malloc(strlen(name) + 1);
                    if ((*person_array)[*person_count].name == NULL) {
                        printf("Oshibka vydeleniya pamyati dlya imeni\n");
                        fclose(file);
                        exit(1);
                    }
                    strcpy((*person_array)[*person_count].name, name);
                    (*person_array)[*person_count].age = age;
                    (*person_count)++;
                }
                break;
            }
        }
    }

    fclose(file);
}

void write_sorting_output(const char* filename, int* int_array, int int_count,
                          Person* person_array, int person_count) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Oshibka sozdaniya faila %s\n", filename);
        return;
    }

    fprintf(file, "=== REZULTATY SORTIROVKI CELYH CHISEL ===\n");
    for (int i = 0; i < int_count; i++) {
        fprintf(file, "%d", int_array[i]);
        if (i < int_count - 1) fprintf(file, " ");
    }
    fprintf(file, "\n\n");

    fprintf(file, "=== REZULTATY SORTIROVKI STRUCT PERSON ===\n");
    for (int i = 0; i < person_count; i++) {
        fprintf(file, "%s %d\n", person_array[i].name, person_array[i].age);
    }

    fclose(file);
}


void free_person_array(Person* array, int count) {
    if (array == NULL) return;

    for (int i = 0; i < count; i++) {
        free(array[i].name);
    }

    free(array);
}


// ============================================
// HELPER FUNCTION: SWAP
// ============================================
static size_t swap_elements(void* a, void* b, size_t size) {
    if (a == b) return 0;

    char* temp = (char*)malloc(size);
    if (temp == NULL) return 0;

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
    return 1; // один swap
}



// ============================================
// BUBBLE SORT
// ============================================
size_t universal_bubble_sort(void* array, int count, size_t size,
    int (*compare)(const void*, const void*)) {
    if (count <= 0 || array == NULL || compare == NULL || size == 0) return 0;

    char* arr = (char*)array;
    size_t moves = 0;

    for (int i = 0; i < count - 1; i++) {
        int swapped = 0;

        for (int j = 0; j < count - i - 1; j++) {
            if (compare(arr + (size_t)j * size, arr + (size_t)(j + 1) * size) > 0) {
                moves += swap_elements(arr + (size_t)j * size, arr + (size_t)(j + 1) * size, size);
                swapped = 1;
            }
        }

        // оптимизаци€: если за проход не было swap Ч массив отсортирован
        if (!swapped) break;
    }

    return moves;
}



// ============================================
// SELECTION SORT
// ============================================
size_t universal_selection_sort(void* array, int count, size_t size,
    int (*compare)(const void*, const void*)) {
    if (count <= 0 || array == NULL || compare == NULL || size == 0) return 0;

    char* arr = (char*)array;
    size_t moves = 0;

    for (int i = 0; i < count - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < count; j++) {
            if (compare(arr + (size_t)j * size, arr + (size_t)min_idx * size) < 0) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            moves += swap_elements(arr + (size_t)i * size, arr + (size_t)min_idx * size, size);
        }
    }

    return moves;
}



// ============================================
// INSERTION SORT
// ============================================
size_t universal_insertion_sort(void* array, int count, size_t size,
    int (*compare)(const void*, const void*)) {
    if (count <= 0 || array == NULL || compare == NULL || size == 0) return 0;

    char* arr = (char*)array;
    char* key = (char*)malloc(size);
    if (key == NULL) return 0;

    size_t moves = 0;

    for (int i = 1; i < count; i++) {
        memcpy(key, arr + (size_t)i * size, size); // копируем ключ
        int j = i - 1;

        while (j >= 0 && compare(arr + (size_t)j * size, key) > 0) {
            memcpy(arr + (size_t)(j + 1) * size, arr + (size_t)j * size, size); // сдвиг
            moves++;
            j--;
        }

        // вставка ключа: считать только если позици€ изменилась
        if (j + 1 != i) {
            memcpy(arr + (size_t)(j + 1) * size, key, size);
            moves++;
        }
    }

    free(key);
    return moves;
}


// ============================================
// SHELL SORT
// ============================================
size_t universal_shell_sort(void* array, int count, size_t size,
                           int (*compare)(const void*, const void*)) {
    if (count <= 0 || array == NULL) return 0;

    char* arr = (char*)array;
    char* temp = (char*)malloc(size);
    if (temp == NULL) return 0;

    size_t moves = 0;

    for (int gap = count / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < count; i++) {
            memcpy(temp, arr + i * size, size);
            int j = i;

            while (j >= gap && compare(arr + (j - gap) * size, temp) > 0) {
                memcpy(arr + j * size, arr + (j - gap) * size, size);
                moves++;
                j -= gap;
            }
            memcpy(arr + j * size, temp, size);
            moves++;
        }
    }

    free(temp);
    return moves;
}


// ============================================
// QUICK SORT
// ============================================
static int partition(void* array, int low, int high, size_t size,
    int (*compare)(const void*, const void*),
    size_t* moves_out) {
    char* arr = (char*)array;
    size_t moves = 0;

    char* pivot = (char*)malloc(size);
    if (pivot == NULL) {
        *moves_out = 0;
        return low;
    }

    memcpy(pivot, arr + (size_t)high * size, size);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(arr + (size_t)j * size, pivot) <= 0) {
            i++;
            moves += swap_elements(arr + (size_t)i * size, arr + (size_t)j * size, size);
        }
    }

    moves += swap_elements(arr + (size_t)(i + 1) * size, arr + (size_t)high * size, size);

    free(pivot);
    *moves_out = moves;
    return i + 1;
}


static size_t quick_sort(void* array, int low, int high, size_t size,
    int (*compare)(const void*, const void*)) {
    if (low >= high) return 0;

    size_t part_moves = 0;
    int pi = partition(array, low, high, size, compare, &part_moves);

    size_t moves = part_moves;
    moves += quick_sort(array, low, pi - 1, size, compare);
    moves += quick_sort(array, pi + 1, high, size, compare);

    return moves;
}

size_t universal_quick_sort(void* array, int count, size_t size,
    int (*compare)(const void*, const void*)) {
    if (count <= 0 || array == NULL || compare == NULL || size == 0) return 0;
    return quick_sort(array, 0, count - 1, size, compare);
}
static size_t heapify(void* array, int n, int i, size_t size,
    int (*compare)(const void*, const void*)) {
    char* arr = (char*)array;
    size_t moves = 0;

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && compare(arr + (size_t)left * size, arr + (size_t)largest * size) > 0) {
        largest = left;
    }

    if (right < n && compare(arr + (size_t)right * size, arr + (size_t)largest * size) > 0) {
        largest = right;
    }

    if (largest != i) {
        moves += swap_elements(arr + (size_t)i * size, arr + (size_t)largest * size, size);
        moves += heapify(array, n, largest, size, compare);
    }

    return moves;
}

size_t universal_heap_sort(void* array, int count, size_t size,
    int (*compare)(const void*, const void*)) {
    if (count <= 0 || array == NULL || compare == NULL || size == 0) return 0;

    char* arr = (char*)array;
    size_t moves = 0;

    for (int i = count / 2 - 1; i >= 0; i--) {
        moves += heapify(array, count, i, size, compare);
    }

    for (int i = count - 1; i > 0; i--) {
        moves += swap_elements(arr, arr + (size_t)i * size, size);
        moves += heapify(array, i, 0, size, compare);
    }

    return moves;
}