#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
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

    // Add an undirected edge
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
    }

    // Prim's Algorithm to find Minimum Spanning Tree (MST)
    void primMST() {
        vector<bool> inMST(numVertices, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int startVertex = 0;

        pq.push({0, startVertex}); // Pair: (weight, vertex)
        int mstCost = 0;

        cout << "Edges in the Minimum Spanning Tree (MST):" << endl;

        while (!pq.empty()) {
            auto [weight, vertex] = pq.top();
            pq.pop();

            if (inMST[vertex]) continue;

            inMST[vertex] = true;
            mstCost += weight;

            for (auto [neighbor, edgeWeight] : adjList[vertex]) {
                if (!inMST[neighbor]) {
                    pq.push({edgeWeight, neighbor});
                }
            }

            if (weight != 0) {
                cout << "Edge: " << vertex << " with weight: " << weight << endl;
            }
        }

        cout << "Total cost of MST: " << mstCost << endl;
    }
};

int main() {
    // Example Usage: Computer Network
    Graph g(6);

    // Add connections (edges with weights)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(4, 5, 6);

    // Find and print MST
    g.primMST();

    return 0;
}
