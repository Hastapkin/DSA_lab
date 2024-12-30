#include <iostream>
#include <vector>
using namespace std;

// Class to represent a graph
class Graph {
private:
    int numVertices;                              // Number of vertices
    vector<vector<int>> adjMatrix;                // Adjacency Matrix
    vector<vector<int>> adjList;                  // Adjacency List

public:
    // Constructor
    Graph(int vertices) : numVertices(vertices) {
        adjMatrix.resize(vertices, vector<int>(vertices, 0)); // Initialize matrix with 0
        adjList.resize(vertices);                             // Initialize empty adjacency list
    }

    // Add an edge (directed)
    void addEdge(int u, int v, int weight = 1) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjMatrix[u][v] = weight;          // Add to matrix
            adjList[u].push_back(v);           // Add to adjacency list
        } else {
            cout << "Error: Invalid vertices!" << endl;
        }
    }

    // Display the adjacency matrix
    void displayMatrix() {
        cout << "\nAdjacency Matrix:" << endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Display the adjacency list
    void displayList() {
        cout << "\nAdjacency List:" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << i << ":";
            for (int v : adjList[i]) {
                cout << " " << v;
            }
            cout << endl;
        }
    }
};

int main() {
    // Example Usage
    int vertices = 5;
    Graph g(vertices);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 2);
    g.addEdge(3, 4);

    // Display the graph
    g.displayMatrix();
    g.displayList();

    return 0;
}
