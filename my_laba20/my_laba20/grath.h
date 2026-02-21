#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>

class Graph {
private:
	std::vector<std::vector<int>> adj_matrix;
	std::vector<bool> visited;
	std::vector<int> path;
	std::ofstream output_file;
	void dfs_helper(int n);
	void bfs_helper(int start_vertex);
	void find_all_paths_helper(int current, int target, std::vector<int>& current_path,
	                           std::vector<std::vector<int>>& all_paths, std::vector<bool>& in_path);

public:
	Graph(const std::vector<std::vector<int>>& adj_matrix);

	static Graph read_from_file(const std::string& filename, int& root_vertex);
	void dfs_to_file(int start_vertex, const std::string& output_filename);
	void bfs_to_file(int start_vertex, const std::string& output_filename);

	void dfs(int n);
	void bfs(int start_vertex);

	// Функции для поиска циклов
	void find_cycles_helper(int current, int start, std::vector<int>& current_path,
	                        std::vector<std::vector<int>>& all_cycles, std::vector<bool>& in_path);
	void find_cycles_to_file(const std::string& output_filename);

	// Функция для поиска критических вершин (точки сочленения для ориентированных графов)
	void find_critical_vertices_to_file(const std::string& output_filename);
};
