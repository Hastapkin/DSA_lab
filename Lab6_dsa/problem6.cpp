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

    // Add an undirected edge
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // BFS to traverse a connected component
    void bfs(int startVertex, vector<bool>& visited, vector<int>& component) {
        queue<int> q;
        q.push(startVertex);
        visited[startVertex] = true;

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            component.push_back(vertex);

            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    // Find all connected components
    void findConnectedComponents() {
        vector<bool> visited(numVertices, false);
        vector<vector<int>> components;

        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                vector<int> component;
                bfs(i, visited, component); // Perform BFS to find the component
                components.push_back(component);
            }
        }

        // Print all components
        cout << "Connected components:" << endl;
        for (int i = 0; i < components.size(); i++) {
            cout << "Component " << i + 1 << ": ";
            for (int vertex : components[i]) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Example Usage
    Graph g(7);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(5, 6);

    // Find connected components
    g.findConnectedComponents();

    return 0;
}
