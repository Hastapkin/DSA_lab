#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<pair<int, int>>> adjList;

public:
    // Constructor
    Graph(int vertices) : numVertices(vertices) {
        adjList.resize(vertices);
    }

    // Add an undirected edge
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    // Find bridges in the graph
    void findBottlenecks() {
        vector<bool> visited(numVertices, false);
        vector<int> discoveryTime(numVertices, -1);
        vector<int> lowTime(numVertices, -1);
        vector<pair<int, int>> bridges;
        int time = 0;

        // Define dfs as a lambda function
        function<void(int, int)> dfs = [&](int vertex, int parent) {
            visited[vertex] = true;
            discoveryTime[vertex] = lowTime[vertex] = ++time;

            for (auto [neighbor, weight] : adjList[vertex]) {
                if (!visited[neighbor]) {
                    dfs(neighbor, vertex);

                    lowTime[vertex] = min(lowTime[vertex], lowTime[neighbor]);

                    if (lowTime[neighbor] > discoveryTime[vertex]) {
                        bridges.push_back({vertex, neighbor});
                    }
                } else if (neighbor != parent) {
                    lowTime[vertex] = min(lowTime[vertex], discoveryTime[neighbor]);
                }
            }
        };

        // Run DFS for all components
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }

        // Print the bridges (bottlenecks)
        cout << "Traffic bottlenecks (bridges):" << endl;
        for (auto [u, v] : bridges) {
            cout << u << " - " << v << endl;
        }
    }
};

int main() {
    // Example Usage
    Graph g(6);

    // Add roads (edges with weights)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 6);

    // Identify traffic bottlenecks
    g.findBottlenecks();

    return 0;
}
