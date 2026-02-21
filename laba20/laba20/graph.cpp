#include "graph.h"
#include <iostream>

using namespace std;

Graph::Graph() : n(0) {}

Graph::Graph(int vertices) : n(vertices) {
    adjMatrix.resize(n, vector<int>(n, 0));
    visited.resize(n, false);
}

bool Graph::loadFromFile(const string& filename, int& root) {
    ifstream input(filename);

    if (!input.is_open()) {
        cerr << "Error opening file " << filename << "!" << endl;
        return false;
    }

    input >> n;

    if (n <= 0) {
        cerr << "Error: invalid number of vertices!" << endl;
        return false;
    }

    adjMatrix.resize(n, vector<int>(n));
    visited.resize(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input >> adjMatrix[i][j];
        }
    }

    input >> root;

    input.close();
    return true;
}

void Graph::addEdge(int from, int to) {
    if (isValidVertex(from) && isValidVertex(to)) {
        adjMatrix[from][to] = 1;
    }
}

void Graph::dfsRecursive(int current, int root, ofstream& output) {
    visited[current] = true;
    path.push_back(current);

    if (current != root) {
        output << "Path to vertex " << current << ": ";
        for (size_t i = 0; i < path.size(); i++) {
            output << path[i];
            if (i < path.size() - 1) {
                output << " -> ";
            }
        }
        output << endl;
    }

    for (int neighbor = 0; neighbor < n; neighbor++) {
        if (adjMatrix[current][neighbor] == 1 && !visited[neighbor]) {
            dfsRecursive(neighbor, root, output);
        }
    }

    path.pop_back();
}

void Graph::performDFS(int root, const string& filename) {
    ofstream output(filename);

    if (!output.is_open()) {
        cerr << "Error creating file " << filename << "!" << endl;
        return;
    }

    if (!isValidVertex(root)) {
        cerr << "Error: root vertex out of range!" << endl;
        output << "Error: root vertex out of range!" << endl;
        output.close();
        return;
    }

    output << "Graph adjacency matrix:" << endl;
    printAdjMatrix(output);
    output << endl;

    output << "Root vertex: " << root << endl;
    output << endl;

    output << "Paths from root to each reachable vertex (DFS):" << endl;
    output << "============================================" << endl;

    fill(visited.begin(), visited.end(), false);
    path.clear();

    dfsRecursive(root, root, output);

    vector<int> unreachable = getUnreachableVertices();
    output << endl;
    output << "Unreachable vertices from root " << root << ": ";

    if (unreachable.empty()) {
        output << "none";
    } else {
        for (size_t i = 0; i < unreachable.size(); i++) {
            output << unreachable[i];
            if (i < unreachable.size() - 1) {
                output << ", ";
            }
        }
    }
    output << endl;

    output.close();
}

int Graph::getVertexCount() const {
    return n;
}

bool Graph::isValidVertex(int vertex) const {
    return vertex >= 0 && vertex < n;
}

void Graph::printAdjMatrix(ofstream& output) const {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            output << adjMatrix[i][j] << " ";
        }
        output << endl;
    }
}

vector<int> Graph::getUnreachableVertices() const {
    vector<int> unreachable;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            unreachable.push_back(i);
        }
    }
    return unreachable;
}
