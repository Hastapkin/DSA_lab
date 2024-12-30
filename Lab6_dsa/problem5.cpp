#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Define a structure to represent a weighted edge
struct Edge {
    int vertex;
    int weight;
};

// Comparator for the priority queue
struct Compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

// Simple Graph Class
class Graph {
private:
    int numVertices;
    vector<vector<Edge>> adjList;

public:
    // Constructor
    Graph(int vertices) : numVertices(vertices) {
        adjList.resize(vertices);
    }

    // Add a weighted edge
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
    }

    // Dijkstra's algorithm
    void dijkstra(int startVertex) {
        vector<int> distances(numVertices, INT_MAX); // Distance from source to all vertices
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq; // Min-heap

        distances[startVertex] = 0;
        pq.push({startVertex, 0});

        while (!pq.empty()) {
            int currentVertex = pq.top().first;
            int currentDistance = pq.top().second;
            pq.pop();

            for (Edge neighbor : adjList[currentVertex]) {
                int newDist = currentDistance + neighbor.weight;

                if (newDist < distances[neighbor.vertex]) {
                    distances[neighbor.vertex] = newDist;
                    pq.push({neighbor.vertex, newDist});
                }
            }
        }

        // Print shortest distances
        cout << "Shortest distances from vertex " << startVertex << ":" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ": " << distances[i] << endl;
        }
    }
};

int main() {
    // Example Usage
    Graph g(5);

    // Add weighted edges
    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 2);

    // Run Dijkstra's Algorithm
    g.dijkstra(0);

    return 0;
}
