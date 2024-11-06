//K-D Tree with Nearest Neighbor Search
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node {
    vector<int> point;
    Node *left, *right;

    Node(vector<int> arr) : point(arr), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, vector<int> point, int depth = 0) {
    if (root == nullptr) {
        return new Node(point);
    }

    int cd = depth % point.size();

    if (point[cd] < root->point[cd]) {
        root->left = insert(root->left, point, depth + 1);
    } else {
        root->right = insert(root->right, point, depth + 1);
    }

    return root;
}

int distance(const vector<int>& a, const vector<int>& b) {
    int dist = 0;
    for (int i = 0; i < a.size(); i++) {
        dist += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return dist;
}

void nearestNeighborSearch(Node* root, const vector<int>& target, int depth, Node*& best, int& bestDist) {
    if (root == nullptr) return;

    int d = distance(root->point, target);
    if (d < bestDist) {
        bestDist = d;
        best = root;
    }

    int cd = depth % target.size();

    Node* nextBranch = (target[cd] < root->point[cd]) ? root->left : root->right;
    Node* otherBranch = (nextBranch == root->left) ? root->right : root->left;

    nearestNeighborSearch(nextBranch, target, depth + 1, best, bestDist);
    if (bestDist > (target[cd] - root->point[cd]) * (target[cd] - root->point[cd])) {
        nearestNeighborSearch(otherBranch, target, depth + 1, best, bestDist);
    }
}

Node* findNearestNeighbor(Node* root, const vector<int>& target) {
    Node* best = nullptr;
    int bestDist = INT_MAX;
    nearestNeighborSearch(root, target, 0, best, bestDist);
    return best;
}

int main() {
    Node* root = nullptr;
    vector<vector<int>> points = {{3, 6}, {17, 15}, {13, 15}, {6, 12}, {9, 1}, {2, 7}, {10, 19}};

    for (const auto& point : points) {
        root = insert(root, point);
    }

    vector<int> target = {10, 19};
    Node* nearest = findNearestNeighbor(root, target);
    cout << "Nearest Neighbor: (";
    for (int val : nearest->point) {
        cout << val << " ";
    }
    cout << ")" << endl;

    return 0;
}
