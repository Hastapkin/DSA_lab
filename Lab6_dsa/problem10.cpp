#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<pair<int, int>>> adjList; // Pair: (neighbor, weight)

public:
    // Constructor
    Graph(int vertices) : numVertices(vertices) {
        adjList.resize(vertices);
    }

    // Add a weighted edge
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
    }

    // Dijkstra's algorithm using a priority queue
    void dijkstra(int startVertex) {
        vector<int> distances(numVertices, INT_MAX); // Store shortest distances
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Min-heap

        distances[startVertex] = 0;
        pq.push({0, startVertex}); // Pair: (distance, vertex)

        while (!pq.empty()) {
            int currentDistance = pq.top().first;
            int currentVertex = pq.top().second;
            pq.pop();

            // Skip processing if we already found a shorter path
            if (currentDistance > distances[currentVertex]) continue;

            for (auto [neighbor, weight] : adjList[currentVertex]) {
                int newDist = currentDistance + weight;
                if (newDist < distances[neighbor]) {
                    distances[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                }
            }
        }

        // Print shortest distances
        cout << "Shortest distances from vertex " << startVertex << ":\n";
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ": ";
            if (distances[i] == INT_MAX) {
                cout << "INF" << endl;
            } else {
                cout << distances[i] << endl;
            }
        }
    }
};

int main() {
    // Example Usage
    Graph g(5);

    // Add edges
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 1);

    // Run Dijkstra's Algorithm
    g.dijkstra(0);

    return 0;
}
