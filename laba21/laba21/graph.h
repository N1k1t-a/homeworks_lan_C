#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define INF INT_MAX

void bellman_ford(int** graph, int vertices, int start_vertex, int* distances);

int has_negative_cycle(int** graph, int vertices, int start_vertex);

void dijkstra(int** graph, int vertices, int start_vertex, int* distances);


int** read_graph_input(const char* filename, int* vertices);

void write_graph_output(const char* filename, int* distances, int vertices, int start_vertex);

void free_graph(int** graph, int vertices);
