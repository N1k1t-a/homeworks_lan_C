#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"
#include "graph.h"


// Helper functions for copying arrays
int* copy_int_array(int* source, int count) {
    if (source == NULL || count <= 0) return NULL;
    int* copy = (int*)malloc(count * sizeof(int));
    if (copy == NULL) return NULL;
    memcpy(copy, source, count * sizeof(int));
    return copy;
}

Person* copy_person_array(Person* source, int count) {
    if (source == NULL || count <= 0) return NULL;
    Person* copy = (Person*)malloc(count * sizeof(Person));
    if (copy == NULL) return NULL;

    for (int i = 0; i < count; i++) {
        copy[i].name = (char*)malloc(strlen(source[i].name) + 1);
        if (copy[i].name == NULL) {
            for (int j = 0; j < i; j++) {
                free(copy[j].name);
            }
            free(copy);
            return NULL;
        }
        strcpy(copy[i].name, source[i].name);
        copy[i].age = source[i].age;
    }
    return copy;
}


int main() {
    printf("========================================\n");
    printf("   LABORATORNAYA RABOTA 21\n");
    printf("========================================\n\n");


    printf("=== TEST 1: SORTIROVKA SLIYANIEM ===\n\n");

    int* int_array = NULL;
    int int_count = 0;
    Person* person_array = NULL;
    int person_count = 0;

    printf("Zagruzka dannykh iz input_sort.txt...\n");
    read_sorting_input("input_sort.txt", &int_array, &int_count,
                       &person_array, &person_count);

    printf("Dannye zagruzheny:\n");
    printf("- Celye chisla: %d elementov\n", int_count);
    printf("- Struktury Person: %d elementov\n\n", person_count);

    if (int_count > 0) {
        printf("Ishodnye celye chisla:\n");
        for (int i = 0; i < int_count; i++) {
            printf("%d ", int_array[i]);
        }
        printf("\n\n");
    }

    if (person_count > 0) {
        printf("Iskhodnye struktury Person:\n");
        for (int i = 0; i < person_count; i++) {
            printf("%s %d\n", person_array[i].name, person_array[i].age);
        }
        printf("\n");
    }

    if (int_count > 0) {
        printf("Sortiruem celye chisla...\n");
        universal_merge_sort(int_array, int_count, sizeof(int), compare_int);
        printf("Gotovo!\n\n");

        printf("Otsortirovanye celye chisla:\n");
        for (int i = 0; i < int_count; i++) {
            printf("%d ", int_array[i]);
        }
        printf("\n\n");
    }

    if (person_count > 0) {
        printf("Sortiruem struktury Person...\n");
        universal_merge_sort(person_array, person_count, sizeof(Person), compare_person);
        printf("Gotovo!\n\n");

        printf("Otsortirovannye struktury Person:\n");
        for (int i = 0; i < person_count; i++) {
            printf("%s %d\n", person_array[i].name, person_array[i].age);
        }
        printf("\n");
    }

    printf("Zapis rezultatov v output_sort.txt...\n");
    write_sorting_output("output_sort.txt", int_array, int_count,
                         person_array, person_count);
    printf("Rezultaty zapisany!\n\n");

    if (int_array) free(int_array);
    if (person_array) free_person_array(person_array, person_count);

    printf("Test 1 zavershen!\n\n");


    // ============================================
    // ADDITIONAL TESTS: 6 NEW SORTING ALGORITHMS
    // ============================================
    printf("========================================\n\n");
    printf("=== DOPOLNITELNYE TESTY: 6 SORTIVOK ===\n\n");

    // Reload data for new tests
    int* original_int_array = NULL;
    int original_int_count = 0;
    Person* original_person_array = NULL;
    int original_person_count = 0;

    read_sorting_input("input_sort.txt", &original_int_array, &original_int_count,
                       &original_person_array, &original_person_count);


    // TEST: BUBBLE SORT
    printf("=== TEST: BUBBLE SORT ===\n");
    int* bubble_int = copy_int_array(original_int_array, original_int_count);
    Person* bubble_person = copy_person_array(original_person_array, original_person_count);

    size_t bubble_int_moves = 0;
    size_t bubble_person_moves = 0;

    if (bubble_int) {
        bubble_int_moves = universal_bubble_sort(bubble_int, original_int_count, sizeof(int), compare_int);
    }
    if (bubble_person) {
        bubble_person_moves = universal_bubble_sort(bubble_person, original_person_count, sizeof(Person), compare_person);
    }

    write_sorting_output("output_bubble.txt", bubble_int, original_int_count,
        bubble_person, original_person_count);
    printf("Rezultaty zapisany v output_bubble.txt\n\n");

    printf("Bubble sort (int): moves = %zu\n", bubble_int_moves);
    printf("Bubble sort (Person): moves = %zu\n", bubble_person_moves);

    free(bubble_int);
    free_person_array(bubble_person, original_person_count);



    // TEST: SELECTION SORT
    printf("=== TEST: SELECTION SORT ===\n");
    int* selection_int = copy_int_array(original_int_array, original_int_count);
    Person* selection_person = copy_person_array(original_person_array, original_person_count);

    size_t selection_int_moves = 0;
    size_t selection_person_moves = 0;

    if (selection_int) {
        selection_int_moves = universal_selection_sort(selection_int, original_int_count, sizeof(int), compare_int);
    }
    if (selection_person) {
        selection_person_moves = universal_selection_sort(selection_person, original_person_count, sizeof(Person), compare_person);
    }

    write_sorting_output("output_selection.txt", selection_int, original_int_count,
        selection_person, original_person_count);
    printf("Rezultaty zapisany v output_selection.txt\n\n");

    printf("Selection sort (int): moves = %zu\n", selection_int_moves);
    printf("Selection sort (Person): moves = %zu\n", selection_person_moves);

    free(selection_int);
    free_person_array(selection_person, original_person_count);


    // TEST: INSERTION SORT
    printf("=== TEST: INSERTION SORT ===\n");
    int* insertion_int = copy_int_array(original_int_array, original_int_count);
    Person* insertion_person = copy_person_array(original_person_array, original_person_count);

    size_t insertion_int_moves = 0;
    size_t insertion_person_moves = 0;

    if (insertion_int) {
        insertion_int_moves = universal_insertion_sort(insertion_int, original_int_count, sizeof(int), compare_int);
    }
    if (insertion_person) {
        insertion_person_moves = universal_insertion_sort(insertion_person, original_person_count, sizeof(Person), compare_person);
    }

    write_sorting_output("output_insertion.txt", insertion_int, original_int_count,
        insertion_person, original_person_count);
    printf("Rezultaty zapisany v output_insertion.txt\n\n");

    printf("Insertion sort (int): moves = %zu\n", insertion_int_moves);
    printf("Insertion sort (Person): moves = %zu\n", insertion_person_moves);

    free(insertion_int);
    free_person_array(insertion_person, original_person_count);


    // TEST: SHELL SORT
    printf("=== TEST: SHELL SORT ===\n");
    int* shell_int = copy_int_array(original_int_array, original_int_count);
    Person* shell_person = copy_person_array(original_person_array, original_person_count);

    size_t shell_int_moves = 0;
    size_t shell_person_moves = 0;

    if (shell_int) {
        shell_int_moves = universal_shell_sort(shell_int, original_int_count, sizeof(int), compare_int);
    }
    if (shell_person) {
        shell_person_moves = universal_shell_sort(shell_person, original_person_count, sizeof(Person), compare_person);
    }

    write_sorting_output("output_shell.txt", shell_int, original_int_count,
                         shell_person, original_person_count);
    printf("Rezultaty zapisany v output_shell.txt\n\n");

    printf("Shell sort (int): moves = %zu\n", shell_int_moves);
    printf("Shell sort (Person): moves = %zu\n", shell_person_moves);

    free(shell_int);
    free_person_array(shell_person, original_person_count);


    // TEST: QUICK SORT
    printf("=== TEST: QUICK SORT ===\n");

    int* quick_int = copy_int_array(original_int_array, original_int_count);
    Person* quick_person = copy_person_array(original_person_array, original_person_count);

    size_t quick_int_moves = 0;
    size_t quick_person_moves = 0;

    if (quick_int) {
        quick_int_moves = universal_quick_sort(quick_int, original_int_count, sizeof(int), compare_int);
    }
    if (quick_person) {
        quick_person_moves = universal_quick_sort(quick_person, original_person_count, sizeof(Person), compare_person);
    }

    write_sorting_output("output_quick.txt", quick_int, original_int_count,
        quick_person, original_person_count);

    printf("Rezultaty zapisany v output_quick.txt\n\n");
    printf("Quick sort (int): moves = %zu\n", quick_int_moves);
    printf("Quick sort (Person): moves = %zu\n", quick_person_moves);

    free(quick_int);
    free_person_array(quick_person, original_person_count);



    // TEST: HEAP SORT
    printf("=== TEST: HEAP SORT ===\n");
    int* heap_int = copy_int_array(original_int_array, original_int_count);
    Person* heap_person = copy_person_array(original_person_array, original_person_count);

    size_t heap_int_moves = 0;
    size_t heap_person_moves = 0;

    if (heap_int) {
        heap_int_moves = universal_heap_sort(heap_int, original_int_count, sizeof(int), compare_int);
    }
    if (heap_person) {
        heap_person_moves = universal_heap_sort(heap_person, original_person_count, sizeof(Person), compare_person);
    }

    write_sorting_output("output_heap.txt", heap_int, original_int_count,
                         heap_person, original_person_count);
    printf("Rezultaty zapisany v output_heap.txt\n\n");

    free(heap_int);
    free_person_array(heap_person, original_person_count);

    // Cleanup original arrays
    free(original_int_array);
    free_person_array(original_person_array, original_person_count);

    printf("Heap sort (int): moves = %zu\n", heap_int_moves);
    printf("Heap sort (Person): moves = %zu\n", heap_person_moves);

    printf("Vse dopolnitelnye testy zaversheny!\n\n");


    printf("========================================\n\n");
    printf("=== TEST 2: ALGORITM BELLMANA-FORDA ===\n\n");

    int vertices = 0;
    int** graph = NULL;

    printf("Zagruzka grafa iz input_graph.txt...\n");
    graph = read_graph_input("input_graph.txt", &vertices);

    if (graph == NULL || vertices == 0) {
        printf("OSHIBKA: Ne udalos zagruzit graf!\n");
        return 1;
    }

    printf("Graf zagruzhen: %d vershin\n\n", vertices);

    printf("Matrica smejnosti:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%4d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int start_vertex = 0;
    printf("Nachal'naya vershina: %d\n\n", start_vertex);

    printf("Proverka na otricatel'nyj cikl...\n");
    if (has_negative_cycle(graph, vertices, start_vertex)) {
        printf("VNIMANIE: Obnaruzhen otricatel'nyj cikl!\n");
        printf("Kratchajshie puti ne opredeleny.\n\n");
    } else {
        printf("Otricatel'nyj cikl ne obnaruzhen.\n\n");

        int* distances = (int*)malloc(vertices * sizeof(int));
        if (distances == NULL) {
            printf("OSHIBKA: Ne udalos vydelit pamyat!\n");
            free_graph(graph, vertices);
            return 1;
        }

        printf("Zapusk algoritma Bellmana-Forda...\n");
        bellman_ford(graph, vertices, start_vertex, distances);
        printf("Gotovo!\n\n");

        printf("Kratchajshie puti iz vershiny %d:\n", start_vertex);
        for (int i = 0; i < vertices; i++) {
            if (distances[i] == INF) {
                printf("Vershina %d: nedostizhima\n", i);
            } else {
                printf("Vershina %d: %d\n", i, distances[i]);
            }
        }
        printf("\n");

        printf("Zapis rezultatov v output_graph.txt...\n");
        write_graph_output("output_graph.txt", distances, vertices, start_vertex);
        printf("Rezultaty zapisany!\n\n");

        free(distances);
    }

    free_graph(graph, vertices);

    printf("Test 2 zavershen!\n\n");


    printf("========================================\n\n");
    printf("=== TEST 3: ALGORITM DEJKSTRY ===\n\n");

    // Reload graph for Dijkstra test
    vertices = 0;
    graph = NULL;

    printf("Zagruzka grafa iz input_graph.txt...\n");
    graph = read_graph_input("input_graph.txt", &vertices);

    if (graph == NULL || vertices == 0) {
        printf("OSHIBKA: Ne udalos zagruzit graf!\n");
        return 1;
    }

    printf("Graf zagruzhen: %d vershin\n\n", vertices);

    printf("Matrica smejnosti:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%4d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    start_vertex = 0;
    printf("Nachal'naya vershina: %d\n\n", start_vertex);

    // Note: Dijkstra doesn't work with negative weights!
    printf("VNIMANIE: Algoritm Dejkstry ne rabotaet s otricatelnymi vesami!\n");
    printf("Rezultat mozhet byt nekorrektnym esli est otricatelnye rebra.\n\n");

    int* dijkstra_distances = (int*)malloc(vertices * sizeof(int));
    if (dijkstra_distances == NULL) {
        printf("OSHIBKA: Ne udalos vydelit pamyat!\n");
        free_graph(graph, vertices);
        return 1;
    }

    printf("Zapusk algoritma Dejkstry...\n");
    dijkstra(graph, vertices, start_vertex, dijkstra_distances);
    printf("Gotovo!\n\n");

    printf("Kratchajshie puti iz vershiny %d (Dejkstra):\n", start_vertex);
    for (int i = 0; i < vertices; i++) {
        if (dijkstra_distances[i] == INF) {
            printf("Vershina %d: nedostizhima\n", i);
        } else {
            printf("Vershina %d: %d\n", i, dijkstra_distances[i]);
        }
    }
    printf("\n");

    printf("Zapis rezultatov v output_dijkstra.txt...\n");
    write_graph_output("output_dijkstra.txt", dijkstra_distances, vertices, start_vertex);
    printf("Rezultaty zapisany!\n\n");

    free(dijkstra_distances);
    free_graph(graph, vertices);

    printf("Test 3 zavershen!\n\n");


    printf("========================================\n");
    printf("   VSE TESTY ZAVERSHENY USPESHNO!\n");
    printf("========================================\n");

    return 0;
}


//Реализовать сортировку слиянием в стиле универсальной сортировки на С. 
// В main должны быть отсортированы массив целых чисел int и массив структур person (имя, возраст). 
// Реализовать алгоритм Беллмана-Форда для поиска кратчайших путей в графе, представленного матрицей смежности. 
// Выписать длины кратчайших путей. 
// выберите еще 6 соритировок и реалзиовать их в том же стиле и сраувинать по эффективности 
// полным перебором и dayxtra полный перебор и сравнить по кол ву операций