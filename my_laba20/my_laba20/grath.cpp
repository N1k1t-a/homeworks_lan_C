#include "grath.h"
#include <sstream>
#include <algorithm>
#include <functional>

Graph::Graph(const std::vector<std::vector<int>>& adj_matrix)
{
    size_t n = adj_matrix.size();
    this->adj_matrix = adj_matrix;
    visited.assign(n, false);
}

Graph Graph::read_from_file(const std::string& filename, int& root_vertex)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open input file: " + filename);
    }

    int n;
    file >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> matrix[i][j];
        }
    }

    file >> root_vertex;
    file.close();

    return Graph(matrix);
}

void Graph::dfs(int n)
{
    if (n >= adj_matrix.size() || n < 0) {
        return;
    }
    if (visited[n]) return;

    visited[n] = true;
    path.push_back(n);

    std::cout << "path to " << n << ": ";
    for (size_t i = 0; i < path.size(); i++) {
        std::cout << path[i];
        if (i < path.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;

    for (size_t i = 0; i < adj_matrix.size(); i++) {
        if (adj_matrix[n][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }

    path.pop_back();
}

void Graph::dfs_helper(int n)
{
    if (n >= adj_matrix.size() || n < 0) {
        return;
    }
    if (visited[n]) return;

    visited[n] = true;
    path.push_back(n);

    output_file << "Path to vertex " << n << ": ";
    for (size_t i = 0; i < path.size(); i++) {
        output_file << path[i];
        if (i < path.size() - 1) {
            output_file << " -> ";
        }
    }
    output_file << std::endl;

    for (size_t i = 0; i < adj_matrix.size(); i++) {
        if (adj_matrix[n][i] == 1 && !visited[i]) {
            dfs_helper(i);
        }
    }

    path.pop_back();
}

void Graph::dfs_to_file(int start_vertex, const std::string& output_filename)
{
    visited.assign(adj_matrix.size(), false);
    path.clear();

    output_file.open(output_filename);
    if (!output_file.is_open()) {
        throw std::runtime_error("Cannot open output file: " + output_filename);
    }

    output_file << "DFS Traversal starting from vertex " << start_vertex << std::endl;
    output_file << "===========================================" << std::endl;

    dfs_helper(start_vertex);

    output_file << "===========================================" << std::endl;
    output_file << "DFS completed." << std::endl;

    output_file.close();
}

void Graph::bfs(int start_vertex)
{
    if (start_vertex >= adj_matrix.size() || start_vertex < 0) {
        return;
    }

    visited.assign(adj_matrix.size(), false);
    std::vector<int> parent(adj_matrix.size(), -1);
    std::queue<int> q;

    q.push(start_vertex);
    visited[start_vertex] = true;

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        // Восстанавливаем путь от start_vertex до n
        std::vector<int> path_to_n;
        int current = n;
        while (current != -1) {
            path_to_n.push_back(current);
            current = parent[current];
        }
        std::reverse(path_to_n.begin(), path_to_n.end());

        // Выводим путь
        std::cout << "Path to vertex " << n << ": ";
        for (size_t i = 0; i < path_to_n.size(); i++) {
            std::cout << path_to_n[i];
            if (i < path_to_n.size() - 1) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;

        // Добавляем соседей в очередь
        for (size_t i = 0; i < adj_matrix.size(); i++) {
            if (adj_matrix[n][i] == 1 && !visited[i]) {
                visited[i] = true;
                parent[i] = n;
                q.push(i);
            }
        }
    }
}

void Graph::bfs_helper(int start_vertex)
{
    if (start_vertex >= adj_matrix.size() || start_vertex < 0) {
        return;
    }

    visited.assign(adj_matrix.size(), false);
    std::vector<int> parent(adj_matrix.size(), -1);
    std::queue<int> q;

    q.push(start_vertex);
    visited[start_vertex] = true;

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        // Восстанавливаем путь от start_vertex до n
        std::vector<int> path_to_n;
        int current = n;
        while (current != -1) {
            path_to_n.push_back(current);
            current = parent[current];
        }
        std::reverse(path_to_n.begin(), path_to_n.end());

        // Выводим путь
        output_file << "Path to vertex " << n << ": ";
        for (size_t i = 0; i < path_to_n.size(); i++) {
            output_file << path_to_n[i];
            if (i < path_to_n.size() - 1) {
                output_file << " -> ";
            }
        }
        output_file << std::endl;

        // Добавляем соседей в очередь
        for (size_t i = 0; i < adj_matrix.size(); i++) {
            if (adj_matrix[n][i] == 1 && !visited[i]) {
                visited[i] = true;
                parent[i] = n;
                q.push(i);
            }
        }
    }
}

void Graph::bfs_to_file(int start_vertex, const std::string& output_filename)
{
    visited.assign(adj_matrix.size(), false);

    output_file.open(output_filename);
    if (!output_file.is_open()) {
        throw std::runtime_error("Cannot open output file: " + output_filename);
    }

    output_file << "BFS Traversal starting from vertex " << start_vertex << std::endl;
    output_file << "===========================================" << std::endl;

    bfs_helper(start_vertex);

    output_file << "===========================================" << std::endl;
    output_file << "BFS completed." << std::endl;

    output_file.close();
}

// Вспомогательная функция для поиска циклов, начинающихся и заканчивающихся в вершине start
void Graph::find_cycles_helper(int current, int start, std::vector<int>& current_path,
                                std::vector<std::vector<int>>& all_cycles, std::vector<bool>& in_path)
{
    current_path.push_back(current);
    in_path[current] = true;

    // Проверяем всех соседей текущей вершины
    for (size_t i = 0; i < adj_matrix.size(); i++) {
        if (adj_matrix[current][i] == 1) {
            // Если нашли ребро обратно в стартовую вершину и путь не пустой - нашли цикл!
            if (i == start && current_path.size() > 1) {
                // Сохраняем найденный цикл
                all_cycles.push_back(current_path);
            }
            // Если вершина еще не в текущем пути - продолжаем поиск
            else if (!in_path[i]) {
                find_cycles_helper(i, start, current_path, all_cycles, in_path);
            }
        }
    }

    // Backtracking
    current_path.pop_back();
    in_path[current] = false;
}

// Поиск всех циклов в графе и запись в файл
void Graph::find_cycles_to_file(const std::string& output_filename)
{
    output_file.open(output_filename);
    if (!output_file.is_open()) {
        throw std::runtime_error("Cannot open output file: " + output_filename);
    }

    output_file << "Cycles in the directed graph" << std::endl;
    output_file << "==========================================================" << std::endl;

    int total_cycles = 0;

    // Ищем циклы, начинающиеся с каждой вершины
    for (size_t start_vertex = 0; start_vertex < adj_matrix.size(); start_vertex++) {
        std::vector<std::vector<int>> cycles;
        std::vector<int> current_path;
        std::vector<bool> in_path(adj_matrix.size(), false);

        // Ищем циклы из текущей вершины
        find_cycles_helper(start_vertex, start_vertex, current_path, cycles, in_path);

        if (!cycles.empty()) {
            output_file << "\nCycles starting from vertex " << start_vertex << ":" << std::endl;
            for (size_t i = 0; i < cycles.size(); i++) {
                output_file << "  Cycle " << (i + 1) << ": ";
                for (size_t j = 0; j < cycles[i].size(); j++) {
                    output_file << cycles[i][j];
                    if (j < cycles[i].size() - 1) {
                        output_file << " -> ";
                    }
                }
                output_file << " -> " << start_vertex << " (back to start)" << std::endl;
                total_cycles++;
            }
        }
    }

    if (total_cycles == 0) {
        output_file << "\nNo cycles found in the graph." << std::endl;
    }
    else {
        output_file << "\n==========================================================" << std::endl;
        output_file << "Total cycles found: " << total_cycles << std::endl;
    }

    output_file << "==========================================================" << std::endl;
    output_file.close();
}

// Поиск критических вершин (точки сочленения для ориентированного графа)
void Graph::find_critical_vertices_to_file(const std::string& output_filename)
{
    output_file.open(output_filename);
    if (!output_file.is_open()) {
        throw std::runtime_error("Cannot open output file: " + output_filename);
    }

    output_file << "Critical Vertices in the directed graph" << std::endl;
    output_file << "==========================================================" << std::endl;
    output_file << "A vertex is critical if removing it disconnects the graph" << std::endl;
    output_file << "or reduces reachability from any starting point" << std::endl;
    output_file << "==========================================================" << std::endl;

    int n = adj_matrix.size();
    std::vector<int> critical_vertices;

    // Для каждой вершины проверяем, является ли она критической
    for (int v = 0; v < n; v++) {
        // Подсчитываем количество достижимых вершин С удалением вершины v
        std::vector<bool> reachable_without_v(n, false);
        int count_without_v = 0;

        for (int start = 0; start < n; start++) {
            if (start == v) continue;

            visited.assign(n, false);
            visited[v] = true;  // "Удаляем" вершину v (помечаем как посещенную)

            // DFS для подсчета достижимых вершин БЕЗ вершины v
            std::function<void(int)> count_reachable = [&](int node) {
                visited[node] = true;
                if (!reachable_without_v[node]) {
                    reachable_without_v[node] = true;
                    count_without_v++;
                }
                for (int i = 0; i < n; i++) {
                    if (adj_matrix[node][i] == 1 && !visited[i]) {
                        count_reachable(i);
                    }
                }
            };

            count_reachable(start);
        }

        // Подсчитываем количество достижимых вершин БЕЗ удаления (в полном графе)
        std::vector<bool> reachable_with_v(n, false);
        int count_with_v = 0;

        for (int start = 0; start < n; start++) {
            visited.assign(n, false);

            std::function<void(int)> count_reachable = [&](int node) {
                visited[node] = true;
                if (!reachable_with_v[node]) {
                    reachable_with_v[node] = true;
                    count_with_v++;
                }
                for (int i = 0; i < n; i++) {
                    if (adj_matrix[node][i] == 1 && !visited[i]) {
                        count_reachable(i);
                    }
                }
            };

            count_reachable(start);
        }

        // Если количество достижимых вершин уменьшилось - вершина критическая
        if (count_without_v < count_with_v) {
            critical_vertices.push_back(v);
        }
    }

    output_file << "\n";
    if (critical_vertices.empty()) {
        output_file << "No critical vertices found." << std::endl;
        output_file << "The graph remains connected regardless of which vertex is removed." << std::endl;
    } else {
        output_file << "Critical vertices found: " << critical_vertices.size() << std::endl;
        output_file << "\n";
        for (size_t i = 0; i < critical_vertices.size(); i++) {
            output_file << "  Vertex " << critical_vertices[i];
            output_file << " - removing it reduces reachability in the graph" << std::endl;
        }
    }

    output_file << "\n==========================================================" << std::endl;
    output_file.close();
}