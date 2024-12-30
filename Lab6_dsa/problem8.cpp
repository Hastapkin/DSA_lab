#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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

    // BFS to find a community (connected component)
    void bfs(int startVertex, vector<bool>& visited, vector<int>& community) {
        queue<int> q;
        q.push(startVertex);
        visited[startVertex] = true;

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            community.push_back(vertex);

            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    // Find all communities
    void detectCommunities() {
        vector<bool> visited(numVertices, false);
        vector<vector<int>> communities;

        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                vector<int> community;
                bfs(i, visited, community);
                communities.push_back(community);
            }
        }

        // Print all communities
        cout << "Detected communities:" << endl;
        for (int i = 0; i < communities.size(); i++) {
            cout << "Community " << i + 1 << ": ";
            for (int vertex : communities[i]) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Example Usage: Social Network Graph
    Graph g(8);

    // Add edges (friendships)
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(3, 4);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(5, 7);

    // Detect and print communities
    g.detectCommunities();

    return 0;
}
