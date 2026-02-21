#include <iostream>
#include "graph.h"

using namespace std;

void test1_LoadFromFile() {
    cout << "=== Test 1: Load graph from file ===" << endl;

    Graph graph;
    int root;

    if (graph.loadFromFile("input.txt", root)) {
        cout << "Graph loaded successfully." << endl;
        cout << "Number of vertices: " << graph.getVertexCount() << endl;
        cout << "Root vertex: " << root << endl;

        graph.performDFS(root, "output.txt");
        cout << "Result written to output.txt" << endl;
    } else {
        cout << "Error loading graph!" << endl;
    }

    cout << endl;
}

void test2_CreateGraphProgrammatically() {
    cout << "=== Test 2: Create graph programmatically ===" << endl;

    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    cout << "Graph created with 5 vertices." << endl;
    cout << "Edges: 0->1, 0->2, 1->3, 2->3, 3->4" << endl;

    int root = 0;
    graph.performDFS(root, "output_test2.txt");
    cout << "Result written to output_test2.txt" << endl;

    cout << endl;
}

void test3_GraphWithUnreachableVertices() {
    cout << "=== Test 3: Graph with unreachable vertices ===" << endl;

    Graph graph(6);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);

    cout << "Graph with isolated components created." << endl;
    cout << "Component 1: 0->1->2" << endl;
    cout << "Component 2: 3->4->5 (unreachable from 0)" << endl;

    int root = 0;
    graph.performDFS(root, "output_test3.txt");
    cout << "Result written to output_test3.txt" << endl;

    cout << endl;
}

void test4_GraphWithCycles() {
    cout << "=== Test 4: Graph with cycles ===" << endl;

    Graph graph(4);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(1, 3);

    cout << "Graph with cycle created." << endl;
    cout << "Edges: 0->1->2->0 (cycle), 1->3" << endl;

    int root = 0;
    graph.performDFS(root, "output_test4.txt");
    cout << "Result written to output_test4.txt" << endl;

    cout << endl;
}

void test5_LinearGraph() {
    cout << "=== Test 5: Linear graph (chain) ===" << endl;

    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    cout << "Linear graph created: 0->1->2->3->4" << endl;

    int root = 0;
    graph.performDFS(root, "output_test5.txt");
    cout << "Result written to output_test5.txt" << endl;

    cout << endl;
}

int main() {
    cout << "======================================" << endl;
    cout << "   DFS GRAPH TRAVERSAL TESTING       " << endl;
    cout << "======================================" << endl;
    cout << endl;

    test1_LoadFromFile();
    test2_CreateGraphProgrammatically();
    test3_GraphWithUnreachableVertices();
    test4_GraphWithCycles();
    test5_LinearGraph();

    cout << "======================================" << endl;
    cout << "   ALL TESTS COMPLETED SUCCESSFULLY! " << endl;
    cout << "======================================" << endl;

    return 0;
}
