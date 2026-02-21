#include "grath.h"
#include <iostream>
#include <vector>
#include <string>


int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "=== Example 1: DFS Console output ===" << std::endl;
    std::vector<std::vector<int>> adjMatrix{
      {0, 1, 1, 0},
      {0, 0, 0, 1},
      {0, 0, 0, 1},
      {0, 0, 0, 0},
    };
    Graph g1(adjMatrix);
    g1.dfs(0);
    std::cout << std::endl;

    std::cout << "=== Example 2: BFS Console output ===" << std::endl;
    Graph g1_bfs(adjMatrix);
    g1_bfs.bfs(0);
    std::cout << std::endl;

    try {
        std::cout << "=== Example 3: DFS File I/O ===" << std::endl;

        std::string input_file = "input1.txt";
        std::string output_file = "output1.txt";

        int root_vertex;
        Graph g2 = Graph::read_from_file(input_file, root_vertex);

        std::cout << "Graph loaded from " << input_file << std::endl;
        std::cout << "Root vertex: " << root_vertex << std::endl;
        std::cout << "Running DFS and writing results to " << output_file << "..." << std::endl;

        g2.dfs_to_file(root_vertex, output_file);

        std::cout << "DFS completed! Check " << output_file << " for results." << std::endl;
        std::cout << std::endl;

        std::cout << "=== Example 4: BFS File I/O ===" << std::endl;

        std::string bfs_output_file = "output_bfs1.txt";

        Graph g2_bfs = Graph::read_from_file(input_file, root_vertex);
        std::cout << "Graph loaded from " << input_file << std::endl;
        std::cout << "Root vertex: " << root_vertex << std::endl;
        std::cout << "Running BFS and writing results to " << bfs_output_file << "..." << std::endl;

        g2_bfs.bfs_to_file(root_vertex, bfs_output_file);

        std::cout << "BFS completed! Check " << bfs_output_file << " for results." << std::endl;
        std::cout << std::endl;

        std::cout << "=== Example 5: Another DFS test case ===" << std::endl;
        input_file = "input2.txt";
        output_file = "output2.txt";

        Graph g3 = Graph::read_from_file(input_file, root_vertex);
        std::cout << "Graph loaded from " << input_file << std::endl;
        std::cout << "Root vertex: " << root_vertex << std::endl;
        std::cout << "Running DFS and writing results to " << output_file << "..." << std::endl;

        g3.dfs_to_file(root_vertex, output_file);
        std::cout << "DFS completed! Check " << output_file << " for results." << std::endl;
        std::cout << std::endl;

        std::cout << "=== Example 6: Another BFS test case ===" << std::endl;
        bfs_output_file = "output_bfs2.txt";

        Graph g3_bfs = Graph::read_from_file(input_file, root_vertex);
        std::cout << "Graph loaded from " << input_file << std::endl;
        std::cout << "Root vertex: " << root_vertex << std::endl;
        std::cout << "Running BFS and writing results to " << bfs_output_file << "..." << std::endl;

        g3_bfs.bfs_to_file(root_vertex, bfs_output_file);
        std::cout << "BFS completed! Check " << bfs_output_file << " for results." << std::endl;
        std::cout << std::endl;

        std::cout << "=== Example 7: Graph with cycles ===" << std::endl;
        std::cout << "Creating a graph with cycles..." << std::endl;
        std::vector<std::vector<int>> cyclicGraph{
            {0, 1, 1, 0, 0},  
            {0, 0, 1, 1, 0},  
            {0, 0, 0, 1, 0},  
            {0, 0, 0, 0, 1},  
            {0, 0, 0, 1, 0}   
        };

        std::cout << "=== Example 8: Finding cycles in the graph ===" << std::endl;
        std::string cycles_output = "output_cycles.txt";

        Graph g6(cyclicGraph);
        std::cout << "Finding all cycles in the graph..." << std::endl;

        g6.find_cycles_to_file(cycles_output);
        std::cout << "Cycle detection completed! Check " << cycles_output << " for results." << std::endl;
        std::cout << std::endl;

        std::cout << "=== Example 9: Finding Critical Vertices (точки сочленения) ===" << std::endl;
        std::string critical_output = "output_critical_vertices.txt";

        Graph g7(cyclicGraph);
        std::cout << "Finding critical vertices in the directed graph..." << std::endl;

        g7.find_critical_vertices_to_file(critical_output);
        std::cout << "Critical vertices detection completed! Check " << critical_output << " for results." << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
