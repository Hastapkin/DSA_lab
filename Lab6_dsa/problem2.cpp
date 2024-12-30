#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Class to represent a graph
class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;

public:
    // Constructor
    Graph(int vertices) : numVertices(vertices) {
        adjList.resize(vertices);
    }

    // Add an edge (directed graph)
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjList[u].push_back(v);
        } else {
            cout << "Error: Invalid vertices!" << endl;
        }
    }

    // Recursive DFS Helper Function
    void dfsRecursiveHelper(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                dfsRecursiveHelper(neighbor, visited);
            }
        }
    }

    // Perform Recursive DFS
    void dfsRecursive(int startVertex) {
        vector<bool> visited(numVertices, false);
        cout << "Recursive DFS starting from vertex " << startVertex << ": ";
        dfsRecursiveHelper(startVertex, visited);
        cout << endl;
    }

    // Perform Iterative DFS
    void dfsIterative(int startVertex) {
        vector<bool> visited(numVertices, false);
        stack<int> s;
        s.push(startVertex);

        cout << "Iterative DFS starting from vertex " << startVertex << ": ";

        while (!s.empty()) {
            int vertex = s.top();
            s.pop();

            if (!visited[vertex]) {
                visited[vertex] = true;
                cout << vertex << " ";
            }

            for (auto it = adjList[vertex].rbegin(); it != adjList[vertex].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Example Usage
    int vertices = 6;
    Graph g(vertices);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    // Perform DFS
    g.dfsRecursive(0); // Recursive DFS
    g.dfsIterative(0); // Iterative DFS

    return 0;
}
