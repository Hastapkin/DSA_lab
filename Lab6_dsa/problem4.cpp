#include <iostream>
#include <vector>
using namespace std;

// Simple Graph Class
class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;

public:
    // Constructor
    Graph(int vertices) : numVertices(vertices) {
        adjList.resize(vertices);
    }

    // Add an edge
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    // Detect cycle in a directed graph using DFS
    bool detectCycleDirectedUtil(int vertex, vector<bool>& visited, vector<bool>& recStack) {
        visited[vertex] = true;
        recStack[vertex] = true;

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                if (detectCycleDirectedUtil(neighbor, visited, recStack)) {
                    return true;
                }
            } else if (recStack[neighbor]) {
                return true;
            }
        }

        recStack[vertex] = false;
        return false;
    }

    bool detectCycleDirected() {
        vector<bool> visited(numVertices, false);
        vector<bool> recStack(numVertices, false);

        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                if (detectCycleDirectedUtil(i, visited, recStack)) {
                    return true;
                }
            }
        }
        return false;
    }

    // Detect cycle in an undirected graph using DFS
    bool detectCycleUndirectedUtil(int vertex, vector<bool>& visited, int parent) {
        visited[vertex] = true;

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                if (detectCycleUndirectedUtil(neighbor, visited, vertex)) {
                    return true;
                }
            } else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

    bool detectCycleUndirected() {
        vector<bool> visited(numVertices, false);

        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                if (detectCycleUndirectedUtil(i, visited, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    // Example Usage: Directed Graph
    Graph directedGraph(4);
    directedGraph.addEdge(0, 1);
    directedGraph.addEdge(1, 2);
    directedGraph.addEdge(2, 0);
    directedGraph.addEdge(3, 1);

    if (directedGraph.detectCycleDirected()) {
        cout << "Cycle detected in directed graph." << endl;
    } else {
        cout << "No cycle in directed graph." << endl;
    }

    // Example Usage: Undirected Graph
    Graph undirectedGraph(4);
    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(1, 2);
    undirectedGraph.addEdge(2, 0);

    if (undirectedGraph.detectCycleUndirected()) {
        cout << "Cycle detected in undirected graph." << endl;
    } else {
        cout << "No cycle in undirected graph." << endl;
    }

    return 0;
}
