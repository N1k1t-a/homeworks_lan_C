#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Graph {
private:
    int n;                          
    vector<vector<int>> adjMatrix;  
    vector<bool> visited;           
    vector<int> path;               

    
    void dfsRecursive(int current, int root, ofstream& output);

public:

    Graph();

 
    Graph(int vertices);


    bool loadFromFile(const string& filename, int& root);

    void addEdge(int from, int to);

 
    void performDFS(int root, const string& filename);

    int getVertexCount() const;

    /**
     * Проверка корректности вершины
     * @param vertex - номер вершины
     * @return true, если вершина корректна
     */
    bool isValidVertex(int vertex) const;

    /**
     * Вывод матрицы смежности в поток
     * @param output - поток вывода
     */
    void printAdjMatrix(ofstream& output) const;

    /**
     * Получение недостижимых вершин
     * @return вектор недостижимых вершин
     */
    vector<int> getUnreachableVertices() const;
};

#endif // GRAPH_H
