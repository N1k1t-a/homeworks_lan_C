#define _CRT_SECURE_NO_WARNINGS
#include "graph.h"


void bellman_ford(int** graph, int vertices, int start_vertex, int* distances) {
    for (int i = 0; i < vertices; i++) {
        distances[i] = INF;
    }
    distances[start_vertex] = 0;

    for (int i = 0; i < vertices - 1; i++) {
        for (int u = 0; u < vertices; u++) {
            if (distances[u] == INF) continue;

            for (int v = 0; v < vertices; v++) {
                if (graph[u][v] != 0) {
                    long long new_dist = (long long)distances[u] + graph[u][v];

                    if (new_dist < distances[v]) {
                        distances[v] = (int)new_dist;
                    }
                }
            }
        }
    }
}

int has_negative_cycle(int** graph, int vertices, int start_vertex) {
    int* distances = (int*)malloc(vertices * sizeof(int));
    if (distances == NULL) return 0;

    bellman_ford(graph, vertices, start_vertex, distances);

    for (int u = 0; u < vertices; u++) {
        if (distances[u] == INF) continue;

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] != 0) {
                long long new_dist = (long long)distances[u] + graph[u][v];

                if (new_dist < distances[v]) {
                    free(distances);
                    return 1;  
                }
            }
        }
    }

    free(distances);
    return 0;
}

// ============================================
// DIJKSTRA ALGORITHM (FULL ENUMERATION)
// ============================================
void dijkstra(int** graph, int vertices, int start_vertex, int* distances) {
    // Array to track visited vertices
    int* visited = (int*)malloc(vertices * sizeof(int));
    if (visited == NULL) return;

    // Initialize distances and visited array
    for (int i = 0; i < vertices; i++) {
        distances[i] = INF;
        visited[i] = 0;  // 0 = not visited
    }
    distances[start_vertex] = 0;

    // Main loop: process all vertices
    for (int count = 0; count < vertices; count++) {
        // Find unvisited vertex with minimum distance (FULL ENUMERATION)
        int min_distance = INF;
        int min_vertex = -1;

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && distances[v] < min_distance) {
                min_distance = distances[v];
                min_vertex = v;
            }
        }

        // If no reachable vertex found, break
        if (min_vertex == -1) break;

        // Mark the vertex as visited
        visited[min_vertex] = 1;

        // Update distances to neighbors
        for (int v = 0; v < vertices; v++) {
            // Check if edge exists (non-zero weight)
            if (graph[min_vertex][v] != 0 && !visited[v]) {
                // Calculate new distance
                long long new_dist = (long long)distances[min_vertex] + graph[min_vertex][v];

                // Update if new distance is shorter
                if (distances[min_vertex] != INF && new_dist < distances[v]) {
                    distances[v] = (int)new_dist;
                }
            }
        }
    }

    free(visited);
}

int** read_graph_input(const char* filename, int* vertices) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Oshibka otkrytiya faila %s\n", filename);
        return NULL;
    }

    int** temp_matrix = (int**)malloc(100 * sizeof(int*));
    if (temp_matrix == NULL) {
        printf("Oshibka vydeleniya pamyati\n");
        fclose(file);
        return NULL;
    }
    int matrix_capacity = 100;
    int matrix_rows = 0;
    *vertices = 0;

    char line[1024];
    int section = 0;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;

        if (strlen(line) == 0) continue;

        if (strstr(line, "MATRICA SMEJNOSTI") != NULL) {
            section = 1;
            continue;
        }

        if (section == 1) {
            if (matrix_rows >= matrix_capacity) {
                matrix_capacity *= 2;
                int** temp = (int**)realloc(temp_matrix, matrix_capacity * sizeof(int*));
                if (temp == NULL) {
                    printf("Oshibka rasshireniya massiva\n");
                    for (int i = 0; i < matrix_rows; i++) free(temp_matrix[i]);
                    free(temp_matrix);
                    fclose(file);
                    return NULL;
                }
                temp_matrix = temp;
            }

            int values[256];
            int count = 0;
            char* token = strtok(line, " \t");
            while (token && count < 256) {
                values[count++] = atoi(token);
                token = strtok(NULL, " \t");
            }

            if (count > 0) {
                temp_matrix[matrix_rows] = (int*)malloc(count * sizeof(int));
                if (temp_matrix[matrix_rows] == NULL) {
                    printf("Oshibka vydeleniya pamyati\n");
                    for (int i = 0; i < matrix_rows; i++) free(temp_matrix[i]);
                    free(temp_matrix);
                    fclose(file);
                    return NULL;
                }
                for (int i = 0; i < count; i++) {
                    temp_matrix[matrix_rows][i] = values[i];
                }
                if (count > *vertices) *vertices = count;
                matrix_rows++;
            }
        }
    }
    fclose(file);

    if (matrix_rows > 0) {
        *vertices = (matrix_rows > *vertices) ? matrix_rows : *vertices;
        int** graph = (int**)malloc(*vertices * sizeof(int*));
        if (graph == NULL) {
            printf("Oshibka vydeleniya pamyati\n");
            for (int i = 0; i < matrix_rows; i++) free(temp_matrix[i]);
            free(temp_matrix);
            return NULL;
        }

        for (int i = 0; i < *vertices; i++) {
            graph[i] = (int*)malloc(*vertices * sizeof(int));
            if (graph[i] == NULL) {
                printf("Oshibka vydeleniya pamyati\n");
                for (int j = 0; j < i; j++) free(graph[j]);
                free(graph);
                for (int j = 0; j < matrix_rows; j++) free(temp_matrix[j]);
                free(temp_matrix);
                return NULL;
            }
            for (int j = 0; j < *vertices; j++) {
                if (i < matrix_rows && j < matrix_rows) {
                    graph[i][j] = temp_matrix[i][j];
                } else {
                    graph[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < matrix_rows; i++) {
            free(temp_matrix[i]);
        }
        free(temp_matrix);

        return graph;
    }

    free(temp_matrix);
    return NULL;
}


void write_graph_output(const char* filename, int* distances, int vertices, int start_vertex) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Oshibka sozdaniya faila %s\n", filename);
        return;
    }

    fprintf(file, "=== REZULTATY ALGORITMA BELLMANA-FORDA ===\n");
    fprintf(file, "Kratchajshie puti iz vershiny %d:\n\n", start_vertex);

    for (int i = 0; i < vertices; i++) {
        if (distances[i] == INF) {
            fprintf(file, "Vershina %d: nedostizhima\n", i);
        } else {
            fprintf(file, "Vershina %d: %d\n", i, distances[i]);
        }
    }

    fclose(file);
}


void free_graph(int** graph, int vertices) {
    if (graph == NULL) return;

    for (int i = 0; i < vertices; i++) {
        free(graph[i]);
    }

    free(graph);
}
