CLASSWORK
1. Implement a binary tree class with methods for insertion, deletion, and searching for values.
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Insert a node into the binary tree
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) return new TreeNode(value);
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Search for a value in the binary tree
bool search(TreeNode* root, int value) {
    if (root == nullptr) return false;
    if (root->data == value) return true;
    return (value < root->data) ? search(root->left, value) : search(root->right, value);
}

// Delete a node from the binary tree
TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == nullptr) return nullptr;
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;
        root->data = findMin(root->right);
        root->right = deleteNode(root->right, root->data);
    }
    return root;
}

 2. Write functions to perform pre-order, in-order, post-order, and level-order traversals of a binary
 tree.
 // Pre-order Traversal
void preOrder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// In-order Traversal
void inOrder(TreeNode* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Post-order Traversal
void postOrder(TreeNode* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Level-order Traversal
#include <queue>
void levelOrder(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

 3. Extend the binary tree class to implement a binary search tree with methods for finding
 minimum and maximum values, checking if the tree is balanced, and calculating its height.
 int findMin(TreeNode* root) {
    while (root->left) root = root->left;
    return root->data;
}

int findMax(TreeNode* root) {
    while (root->right) root = root->right;
    return root->data;
}

int height(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

 4. Write a function to calculate the diameter (the longest path between any two nodes) of a
 binary tree.
 int diameter(TreeNode* root, int& diameterLength) {
    if (root == nullptr) return 0;
    int leftHeight = diameter(root->left, diameterLength);
    int rightHeight = diameter(root->right, diameterLength);
    diameterLength = max(diameterLength, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}

int calculateDiameter(TreeNode* root) {
    int diameterLength = 0;
    diameter(root, diameterLength);
    return diameterLength;
}

 5. Write a function to calculate the height of a binary tree.
 int height(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

 6. Implement a function to determine if a binary tree is height-balanced (where the height of the
 two subtrees of any node differs by no more than one).
 bool isBalanced(TreeNode* root) {
    if (root == nullptr) return true;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

 7. Write a function to find the lowest common ancestor of two given nodes in a binary search
 tree.
 TreeNode* findLCA(TreeNode* root, int n1, int n2) {
    if (root == nullptr) return nullptr;
    if (root->data > n1 && root->data > n2) return findLCA(root->left, n1, n2);
    if (root->data < n1 && root->data < n2) return findLCA(root->right, n1, n2);
    return root;
}

 8. Implement level-order traversal of a binary tree using a queue and return the values in each
 level as separate lists.
 #include <vector>
vector<vector<int>> levelOrderWithLevels(TreeNode* root) {
    vector<vector<int>> levels;
    if (root == nullptr) return levels;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; ++i) {
            TreeNode* curr = q.front();
            q.pop();
            level.push_back(curr->data);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        levels.push_back(level);
    }
    return levels;
}

 9. Write a function to find the maximum path sum in a binary tree, where the path may start
 and end at any node.
 int maxPathSum(TreeNode* root, int& globalMax) {
    if (root == nullptr) return 0;
    int left = max(0, maxPathSum(root->left, globalMax));
    int right = max(0, maxPathSum(root->right, globalMax));
    globalMax = max(globalMax, left + right + root->data);
    return max(left, right) + root->data;
}

int findMaxPathSum(TreeNode* root) {
    int globalMax = INT_MIN;
    maxPathSum(root, globalMax);
    return globalMax;
}

 10. Given arrays representing the inorder and postorder traversals of a binary tree, reconstruct
 the original tree.
 TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int& postIndex) {
    if (inStart > inEnd) return nullptr;
    TreeNode* root = new TreeNode(postorder[postIndex--]);
    int inIndex = find(inorder.begin(), inorder.end(), root->data) - inorder.begin();
    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);
    return root;
}

 11. Implement vertical order traversal of a binary tree and return the values in vertical slices.
 #include <map>
#include <vector>
#include <queue>
map<int, vector<int>> verticalOrder(TreeNode* root) {
    map<int, vector<int>> result;
    if (root == nullptr) return result;

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, level] = q.front();
        q.pop();
        result[level].push_back(node->data);
        if (node->left) q.push({node->left, level - 1});
        if (node->right) q.push({node->right, level + 1});
    }
    return result;
}

 12. Write an algorithm to find the lowest common ancestor (LCA) of two nodes in a binary tree.
 TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Base case
    if (root == nullptr || root == p || root == q) {
        return root;
    }

    // Recurse on left and right subtrees
    TreeNode* leftLCA = findLCA(root->left, p, q);
    TreeNode* rightLCA = findLCA(root->right, p, q);

    // If nodes are found on both sides, root is the LCA
    if (leftLCA != nullptr && rightLCA != nullptr) {
        return root;
    }

    // Otherwise, return the non-null result
    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;        // Node 5
    TreeNode* q = root->left->right->right; // Node 4

    TreeNode* lca = findLCA(root, p, q);
    if (lca) {
        cout << "LCA of " << p->data << " and " << q->data << " is " << lca->data << endl;
    } else {
        cout << "LCA not found" << endl;
    }

    return 0;
}

 13. Given two binary trees, merge them into one by adding overlapping nodes together.
 TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1) return t2;
    if (!t2) return t1;
    t1->data += t2->data;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}
