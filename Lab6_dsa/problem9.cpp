#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjList;
    vector<int> outDegree;

public:
    // Constructor
    Graph(int vertices) : numVertices(vertices) {
        adjList.resize(vertices);
        outDegree.resize(vertices, 0);
    }

    // Add a directed edge
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        outDegree[u]++;
    }

    // PageRank algorithm
    void pageRank(double dampingFactor = 0.85, int maxIterations = 100, double tolerance = 1e-6) {
        vector<double> rank(numVertices, 1.0 / numVertices); // Initialize ranks
        vector<double> newRank(numVertices, 0.0);

        for (int iter = 0; iter < maxIterations; iter++) {
            for (int i = 0; i < numVertices; i++) {
                newRank[i] = (1.0 - dampingFactor) / numVertices; // Base rank

                for (int j = 0; j < numVertices; j++) {
                    if (find(adjList[j].begin(), adjList[j].end(), i) != adjList[j].end()) {
                        newRank[i] += dampingFactor * (rank[j] / outDegree[j]);
                    }
                }
            }

            // Check for convergence
            double diff = 0.0;
            for (int i = 0; i < numVertices; i++) {
                diff += fabs(newRank[i] - rank[i]);
                rank[i] = newRank[i];
            }

            if (diff < tolerance) {
                cout << "PageRank converged after " << iter + 1 << " iterations.\n";
                break;
            }
        }

        // Print final ranks
        cout << "PageRank scores:\n";
        for (int i = 0; i < numVertices; i++) {
            cout << "Page " << i << ": " << fixed << setprecision(6) << rank[i] << endl;
        }
    }
};

int main() {
    // Example Usage
    Graph g(4);

    // Add directed edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);

    // Run PageRank
    g.pageRank();

    return 0;
}
