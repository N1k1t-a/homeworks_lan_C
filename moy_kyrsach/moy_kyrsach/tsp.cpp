#include "tsp.h"
#include <fstream>
#include <algorithm>
#include <limits>
#include <iostream>

static void my_reverse(std::vector<int>& a, int left, int right) {
    while (left < right) {
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;

        ++left;
        --right;
    }
}

static bool my_next_permutation_int(std::vector<int>& a) {
    const int n = static_cast<int>(a.size());
    if (n < 2) return false;

    // 1) Находим справа налево первый индекс i, где a[i] < a[i+1]
    int i = n - 2;
    while (i >= 0 && a[i] >= a[i + 1]) {
        --i;
    }

    // Если такого i нет — перестановка последняя, сбрасываем в первую
    if (i < 0) {
        my_reverse(a, 0, n - 1);
        return false;
    }

    // 2) Находим справа налево первый индекс j, где a[j] > a[i]
    int j = n - 1;
    while (a[j] <= a[i]) {
        --j;
    }

    // 3) Меняем a[i] и a[j]
    std::swap(a[i], a[j]);

    // 4) Разворачиваем суффикс (i+1 .. конец)
    my_reverse(a, 0, n - 1);

    return true;
}

bool loadGraph(const std::string& filename, std::vector<std::vector<int>>& graph) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return false;
    }

    int n;
    file >> n;

    if (n <= 0) {
        std::cerr << "Error: Invalid number of vertices" << std::endl;
        return false;
    }

    graph.resize(n, std::vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> graph[i][j];
        }
    }

    file.close();
    return true;
}

int calculatePathLength(const std::vector<std::vector<int>>& graph, const std::vector<int>& path) {
    int length = 0;
    int n = static_cast<int>(path.size());

    for (int i = 0; i < n - 1; i++) {
        int from = path[i];
        int to = path[i + 1];

        if (graph[from][to] == 0 && from != to) {
            return -1;  // Нет пути между вершинами
        }

        length += graph[from][to];
    }

    // Добавляем путь от последней вершины к первой (замыкаем цикл)
    int from = path[n - 1];
    int to = path[0];

    if (graph[from][to] == 0 && from != to) {
        return -1;
    }

    length += graph[from][to];

    return length;
}

TSPResult solveTSP(const std::vector<std::vector<int>>& graph) {
    TSPResult result;
    result.minDistance = std::numeric_limits<int>::max();

    int n = static_cast<int>(graph.size());

    if (n == 0) {
        result.minDistance = 0;
        return result;
    }

    // Создаем начальную перестановку (0, 1, 2, ..., n-1)
    std::vector<int> vertices(n);
    for (int i = 0; i < n; i++) {
        vertices[i] = i;
    }

    // Перебираем все перестановки
    do {
        int currentLength = calculatePathLength(graph, vertices);

        if (currentLength != -1 && currentLength < result.minDistance) {
            result.minDistance = currentLength;
            result.bestPath = vertices;
        }
    } while (my_next_permutation_int(vertices)); // <-- замена std::next_permutation

    return result;
}

bool saveGraphviz(const std::string& filename,
    const std::vector<std::vector<int>>& graph,
    const TSPResult& result) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return false;
    }

    file << "digraph TSP {" << std::endl;

    // Выводим рёбра оптимального пути
    int n = static_cast<int>(result.bestPath.size());
    for (int i = 0; i < n; i++) {
        int from = result.bestPath[i];
        int to = result.bestPath[(i + 1) % n];  // % n для замыкания цикла
        int weight = graph[from][to];

        file << "    " << from << " -> " << to
            << " [label=\"" << weight << "\"];" << std::endl;
    }

    // Добавляем метку с минимальным расстоянием
    file << "    label = \"Minimum distance: " << result.minDistance << "\";" << std::endl;

    file << "}" << std::endl;

    file.close();
    return true;
}
