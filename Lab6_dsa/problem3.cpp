#include <iostream>
#include <vector>
#include <queue>
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

    // Perform BFS
    void bfs(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        q.push(startVertex);
        visited[startVertex] = true;

        cout << "BFS starting from vertex " << startVertex << ": ";

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";

            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Example Usage
    Graph g(6);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    // Perform BFS
    g.bfs(0);

    return 0;
}
