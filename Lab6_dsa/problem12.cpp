#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;

public:
    // Constructor
    Graph(int vertices) : numVertices(vertices) {
        adjList.resize(vertices);
    }

    // Add an undirected edge (friendship)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Degree centrality: Find the most influential user(s) based on the number of connections
    void findInfluentialUsers() {
        vector<int> degree(numVertices, 0);

        // Calculate degree for each user
        for (int i = 0; i < numVertices; i++) {
            degree[i] = adjList[i].size();
        }

        // Find the maximum degree
        int maxDegree = *max_element(degree.begin(), degree.end());

        // Print influential users
        cout << "Most influential user(s) (based on degree centrality):" << endl;
        for (int i = 0; i < numVertices; i++) {
            if (degree[i] == maxDegree) {
                cout << "User " << i << " with " << maxDegree << " connections." << endl;
            }
        }
    }

    // Find communities (connected components)
    void findCommunities() {
        vector<bool> visited(numVertices, false);
        vector<vector<int>> communities;

        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                vector<int> community;
                queue<int> q;

                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int user = q.front();
                    q.pop();
                    community.push_back(user);

                    for (int friendId : adjList[user]) {
                        if (!visited[friendId]) {
                            visited[friendId] = true;
                            q.push(friendId);
                        }
                    }
                }
                communities.push_back(community);
            }
        }

        // Print all communities
        cout << "Detected communities:" << endl;
        for (int i = 0; i < communities.size(); i++) {
            cout << "Community " << i + 1 << ": ";
            for (int user : communities[i]) {
                cout << user << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Example Usage: Social Network
    Graph g(8);

    // Add friendships
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(3, 4);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(5, 7);

    // Find influential users
    g.findInfluentialUsers();

    // Find and print communities
    g.findCommunities();

    return 0;
}
