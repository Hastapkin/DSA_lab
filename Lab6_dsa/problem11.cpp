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
        adjList[v].push_back({u, weight}); // Undirected graph
    }

    // Dijkstra's algorithm to find the shortest route
    vector<int> dijkstra(int startVertex, int endVertex) {
        vector<int> distances(numVertices, INT_MAX); // Store shortest distances
        vector<int> previous(numVertices, -1);       // Store path information
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Min-heap

        distances[startVertex] = 0;
        pq.push({0, startVertex}); // Pair: (distance, vertex)

        while (!pq.empty()) {
            int currentDistance = pq.top().first;
            int currentVertex = pq.top().second;
            pq.pop();

            if (currentVertex == endVertex) break; // Stop if we've reached the destination

            if (currentDistance > distances[currentVertex]) continue;

            for (auto [neighbor, weight] : adjList[currentVertex]) {
                int newDist = currentDistance + weight;
                if (newDist < distances[neighbor]) {
                    distances[neighbor] = newDist;
                    previous[neighbor] = currentVertex;
                    pq.push({newDist, neighbor});
                }
            }
        }

        // Reconstruct the path from startVertex to endVertex
        vector<int> path;
        for (int at = endVertex; at != -1; at = previous[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());

        // Return the path
        return path;
    }
};

int main() {
    // Example Usage
    Graph g(6);

    // Add edges (delivery points and distances)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(3, 4, 6);
    g.addEdge(4, 5, 3);
    g.addEdge(3, 5, 4);

    int startPoint = 0, endPoint = 5;

    // Find the shortest route
    vector<int> route = g.dijkstra(startPoint, endPoint);

    // Output the route
    cout << "Shortest route from " << startPoint << " to " << endPoint << ": ";
    for (int vertex : route) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
