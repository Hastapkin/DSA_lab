#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <cmath>
using namespace std;

class RecommendationSystem {
private:
    int numUsers;
    int numItems;
    vector<vector<int>> userItemMatrix; // Interaction matrix

public:
    // Constructor
    RecommendationSystem(int users, int items) : numUsers(users), numItems(items) {
        userItemMatrix.resize(users, vector<int>(items, 0));
    }

    // Add a user-item interaction
    void addInteraction(int user, int item) {
        if (user < numUsers && item < numItems) {
            userItemMatrix[user][item] = 1; // Mark interaction
        }
    }

    // Compute similarity between two users
    double computeSimilarity(int user1, int user2) {
        double dotProduct = 0, norm1 = 0, norm2 = 0;

        for (int i = 0; i < numItems; i++) {
            dotProduct += userItemMatrix[user1][i] * userItemMatrix[user2][i];
            norm1 += userItemMatrix[user1][i];
            norm2 += userItemMatrix[user2][i];
        }

        if (norm1 == 0 || norm2 == 0) return 0; // Avoid division by zero
        return dotProduct / (sqrt(norm1) * sqrt(norm2));
    }

    // Recommend items for a user
    void recommendItems(int user) {
        vector<double> similarityScores(numUsers, 0);

        // Compute similarity scores
        for (int otherUser = 0; otherUser < numUsers; otherUser++) {
            if (otherUser != user) {
                similarityScores[otherUser] = computeSimilarity(user, otherUser);
            }
        }

        // Calculate recommendation scores for each item
        vector<double> recommendationScores(numItems, 0);
        for (int item = 0; item < numItems; item++) {
            if (userItemMatrix[user][item] == 0) { // Only recommend unseen items
                for (int otherUser = 0; otherUser < numUsers; otherUser++) {
                    recommendationScores[item] += similarityScores[otherUser] * userItemMatrix[otherUser][item];
                }
            }
        }

        // Recommend items with highest scores
        cout << "Recommended items for user " << user << ": ";
        for (int i = 0; i < numItems; i++) {
            if (recommendationScores[i] > 0) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    // Example Usage: Recommendation System
    int users = 4;
    int items = 5;
    RecommendationSystem system(users, items);

    // Add user-item interactions
    system.addInteraction(0, 0);
    system.addInteraction(0, 1);
    system.addInteraction(1, 1);
    system.addInteraction(1, 2);
    system.addInteraction(2, 2);
    system.addInteraction(2, 3);
    system.addInteraction(3, 3);
    system.addInteraction(3, 4);

    // Recommend items for a specific user
    system.recommendItems(0);
    system.recommendItems(1);

    return 0;
}
