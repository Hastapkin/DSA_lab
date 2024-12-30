#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Simple Graph Class
class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;
    int time;

    // Utility function for finding bridges using DFS
    void findBridgesUtil(int vertex, vector<bool>& visited, vector<int>& discoveryTime, 
                         vector<int>& lowTime, int parent, vector<pair<int, int>>& bridges) {
        visited[vertex] = true;
        discoveryTime[vertex] = lowTime[vertex] = ++time;

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                findBridgesUtil(neighbor, visited, discoveryTime, lowTime, vertex, bridges);

                // Update the low time of the current vertex
                lowTime[vertex] = min(lowTime[vertex], lowTime[neighbor]);

                // Check if the edge is a bridge
                if (lowTime[neighbor] > discoveryTime[vertex]) {
                    bridges.push_back({vertex, neighbor});
                }
            } else if (neighbor != parent) {
                // Update the low time of the current vertex for back edge
                lowTime[vertex] = min(lowTime[vertex], discoveryTime[neighbor]);
            }
        }
    }

public:
    // Constructor
    Graph(int vertices) : numVertices(vertices), time(0) {
        adjList.resize(vertices);
    }

    // Add an undirected edge
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Function to find all bridges in the graph
    void findBridges() {
        vector<bool> visited(numVertices, false);
        vector<int> discoveryTime(numVertices, -1);
        vector<int> lowTime(numVertices, -1);
        vector<pair<int, int>> bridges;

        // Call the utility function for each component
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                findBridgesUtil(i, visited, discoveryTime, lowTime, -1, bridges);
            }
        }

        // Print all bridges
        cout << "Bridges in the graph:" << endl;
        for (auto bridge : bridges) {
            cout << bridge.first << " - " << bridge.second << endl;
        }
    }
};

int main() {
    // Example Usage
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    // Find and print bridges
    g.findBridges();

    return 0;
}
