//1
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct FileSystemNode {
    string name;
    bool isDirectory;
    vector<FileSystemNode*> children;

    FileSystemNode(string name, bool isDirectory) : name(name), isDirectory(isDirectory) {}

    void addChild(FileSystemNode* child) {
        children.push_back(child);
    }

    // Method to display the file system tree (DFS traversal)
    void display(int depth = 0) {
        for (int i = 0; i < depth; ++i) cout << "  ";
        cout << (isDirectory ? "[D] " : "[F] ") << name << endl;
        for (auto child : children) {
            child->display(depth + 1);
        }
    }
};

int main() {
    FileSystemNode* root = new FileSystemNode("root", true);
    FileSystemNode* dir1 = new FileSystemNode("dir1", true);
    FileSystemNode* file1 = new FileSystemNode("file1.txt", false);

    root->addChild(dir1);
    dir1->addChild(file1);

    root->display();
    return 0;
}
//2

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct XMLNode {
    string tagName;
    unordered_map<string, string> attributes;
    vector<XMLNode*> children;

    XMLNode(string tagName) : tagName(tagName) {}
};

void parseXML(const string& xml, XMLNode* root) {
    // Simple XML parsing logic to build the tree (this could be extended)
    // Example assumes very simple structure, skipping validation or attribute parsing.
}

int main() {
    XMLNode* root = new XMLNode("root");
    XMLNode* child1 = new XMLNode("child");
    child1->attributes["attr"] = "value";

    root->children.push_back(child1);

    // Display the XML tree
    cout << "Root tag: " << root->tagName << endl;
    for (auto child : root->children) {
        cout << "Child tag: " << child->tagName << ", Attr: " << child->attributes["attr"] << endl;
    }

    return 0;
}
//3

#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int freq) : data(data), frequency(freq), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->frequency > r->frequency;
    }
};

HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& freqMap) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

    // Create leaf nodes and add them to the min heap
    for (auto& pair : freqMap) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    // Build the Huffman Tree
    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top(); minHeap.pop();
        HuffmanNode* right = minHeap.top(); minHeap.pop();

        HuffmanNode* newNode = new HuffmanNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    return minHeap.top(); // Root of the Huffman Tree
}

int main() {
    unordered_map<char, int> freqMap = {{'a', 5}, {'b', 1}, {'c', 3}, {'d', 2}};
    
    HuffmanNode* root = buildHuffmanTree(freqMap);
    
    // Print the Huffman tree (simplified)
    cout << "Huffman Tree root frequency: " << root->frequency << endl;

    return 0;
}
//4

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct GameNode {
    vector<vector<char>> board;
    GameNode* left;   // Possible move for 'X'
    GameNode* right;  // Possible move for 'O'
    int score;        // Minimax score
};

int minimax(GameNode* node, bool isMaximizingPlayer) {
    // Base case: check for win/loss/draw (simplified)
    if (/* check for win condition */) return 10;
    if (/* check for loss condition */) return -10;
    if (/* check for draw */) return 0;

    if (isMaximizingPlayer) {
        int best = INT_MIN;
        for (/* possible moves */) {
            best = max(best, minimax(node->left, false));  // Recursively minimize
        }
        return best;
    } else {
        int best = INT_MAX;
        for (/* possible moves */) {
            best = min(best, minimax(node->right, true));  // Recursively maximize
        }
        return best;
    }
}

int main() {
    // Simple example to demonstrate minimax (full game logic needs to be implemented)
    return 0;
}
//5

#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

struct ExpressionNode {
    char value;
    ExpressionNode* left;
    ExpressionNode* right;

    ExpressionNode(char value) : value(value), left(nullptr), right(nullptr) {}
};

int evaluate(ExpressionNode* root) {
    // Recursive function to evaluate the expression tree
    if (!root) return 0;
    if (!root->left && !root->right) return root->value - '0';  // Leaf node (operand)

    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    if (root->value == '+') return leftVal + rightVal;
    if (root->value == '-') return leftVal - rightVal;
    if (root->value == '*') return leftVal * rightVal;
    if (root->value == '/') return leftVal / rightVal;

    return 0;
}

int main() {
    // Example: (3 + 5) * (2 - 8)
    ExpressionNode* root = new ExpressionNode('*');
    root->left = new ExpressionNode('+');
    root->left->left = new ExpressionNode('3');
    root->left->right = new ExpressionNode('5');
    root->right = new ExpressionNode('-');
    root->right->left = new ExpressionNode('2');
    root->right->right = new ExpressionNode('8');

    cout << "Result: " << evaluate(root) << endl;
    return 0;
}
//6
#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>

using namespace std;

struct MerkleNode {
    string hash;
    MerkleNode* left;
    MerkleNode* right;

    MerkleNode(string hash) : hash(hash), left(nullptr), right(nullptr) {}
};

string sha256(const string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256_ctx;
    SHA256_Init(&sha256_ctx);
    SHA256_Update(&sha256_ctx, data.c_str(), data.length());
    SHA256_Final(hash, &sha256_ctx);
    char buf[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(buf + (i * 2), "%02x", hash[i]);
    }
    return string(buf);
}

MerkleNode* buildMerkleTree(const vector<string>& transactions) {
    vector<MerkleNode*> nodes;

    for (const auto& txn : transactions) {
        nodes.push_back(new MerkleNode(sha256(txn)));
    }

    while (nodes.size() > 1) {
        vector<MerkleNode*> nextLevel;
        for (size_t i = 0; i < nodes.size(); i += 2) {
            if (i + 1 < nodes.size()) {
                string concatenatedHash = nodes[i]->hash + nodes[i + 1]->hash;
                string parentHash = sha256(concatenatedHash);
                MerkleNode* parentNode = new MerkleNode(parentHash);
                parentNode->left = nodes[i];
                parentNode->right = nodes[i + 1];
                nextLevel.push_back(parentNode);
            } else {
                nextLevel.push_back(nodes[i]);
            }
        }
        nodes = nextLevel;
    }

    return nodes.empty() ? nullptr : nodes[0];
}

int main() {
    vector<string> transactions = {"tx1", "tx2", "tx3", "tx4"};
    MerkleNode* root = buildMerkleTree(transactions);
    cout << "Merkle root: " << root->hash << endl;
    return 0;
}
//7
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct EmployeeNode {
    string name;
    vector<EmployeeNode*> subordinates;

    EmployeeNode(string name) : name(name) {}

    void addSubordinate(EmployeeNode* emp) {
        subordinates.push_back(emp);
    }

    void display(int depth = 0) {
        for (int i = 0; i < depth; ++i) cout << "  ";
        cout << name << endl;
        for (auto& emp : subordinates) {
            emp->display(depth + 1);
        }
    }
};

int main() {
    EmployeeNode* CEO = new EmployeeNode("CEO");
    EmployeeNode* manager = new EmployeeNode("Manager");
    EmployeeNode* employee = new EmployeeNode("Employee");

    CEO->addSubordinate(manager);
    manager->addSubordinate(employee);

    CEO->display();
    return 0;
}
//8
#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>

using namespace std;

// Merkle Tree Node structure
struct MerkleNode {
    string hash;  // The hash value for the node
    MerkleNode* left;  // Left child node
    MerkleNode* right; // Right child node

    MerkleNode(string hash) : hash(hash), left(nullptr), right(nullptr) {}
};

// Function to compute SHA256 hash of a string
string sha256(const string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256_ctx;
    SHA256_Init(&sha256_ctx);
    SHA256_Update(&sha256_ctx, data.c_str(), data.length());
    SHA256_Final(hash, &sha256_ctx);
    char buf[2 * SHA256_DIGEST_LENGTH + 1];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(buf + (i * 2), "%02x", hash[i]);
    }
    return string(buf);
}

// Function to build the Merkle tree from a list of transactions
MerkleNode* buildMerkleTree(const vector<string>& transactions) {
    vector<MerkleNode*> nodes;

    // Step 1: Create leaf nodes for each transaction
    for (const auto& txn : transactions) {
        nodes.push_back(new MerkleNode(sha256(txn)));
    }

    // Step 2: Pair nodes and create parent nodes by hashing their combined values
    while (nodes.size() > 1) {
        vector<MerkleNode*> nextLevel;
        for (size_t i = 0; i < nodes.size(); i += 2) {
            if (i + 1 < nodes.size()) {
                // Concatenate the hashes of two child nodes and hash them
                string concatenatedHash = nodes[i]->hash + nodes[i + 1]->hash;
                string parentHash = sha256(concatenatedHash);

                // Create the parent node and link the children
                MerkleNode* parentNode = new MerkleNode(parentHash);
                parentNode->left = nodes[i];
                parentNode->right = nodes[i + 1];
                nextLevel.push_back(parentNode);
            } else {
                // Odd number of nodes: carry the last one up to the next level
                nextLevel.push_back(nodes[i]);
            }
        }
        nodes = nextLevel;  // Move to the next level
    }

    return nodes.empty() ? nullptr : nodes[0];  // Return the root of the Merkle tree
}

// Function to display the Merkle tree (for debugging purposes)
void displayMerkleTree(MerkleNode* root, int depth = 0) {
    if (!root) return;

    // Display the current node's hash
    for (int i = 0; i < depth; ++i) cout << "  ";  // Indentation for visual hierarchy
    cout << root->hash << endl;

    // Recursively display left and right subtrees
    displayMerkleTree(root->left, depth + 1);
    displayMerkleTree(root->right, depth + 1);
}

int main() {
    // Example transactions (in a real blockchain, these would be blocks or transaction data)
    vector<string> transactions = {"tx1", "tx2", "tx3", "tx4"};

    // Step 1: Build the Merkle tree from the transactions
    MerkleNode* root = buildMerkleTree(transactions);

    // Step 2: Display the Merkle tree (root and leaf nodes)
    cout << "Merkle Tree Root Hash: " << root->hash << endl;
    displayMerkleTree(root);

    return 0;
}

//9.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct PhylogeneticNode {
    string species;
    vector<PhylogeneticNode*> descendants;

    PhylogeneticNode(string species) : species(species) {}

    void addDescendant(PhylogeneticNode* descendant) {
        descendants.push_back(descendant);
    }

    void display(int depth = 0) {
        for (int i = 0; i < depth; ++i) cout << "  ";
        cout << species << endl;
        for (auto& descendant : descendants) {
            descendant->display(depth + 1);
        }
    }
};

int main() {
    PhylogeneticNode* root = new PhylogeneticNode("Common Ancestor");
    PhylogeneticNode* speciesA = new PhylogeneticNode("Species A");
    PhylogeneticNode* speciesB = new PhylogeneticNode("Species B");

    root->addDescendant(speciesA);
    root->addDescendant(speciesB);

    root->display();
    return 0;
}
10. Trie Data Structure
A trie (prefix tree) for storing strings efficiently.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TrieNode {
    bool isEndOfWord;
    vector<TrieNode*> children;

    TrieNode() : isEndOfWord(false), children(26, nullptr) {}
};

void insert(TrieNode* root, const string& word) {
    TrieNode* current = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (!current->children[index]) {
            current->children[index] = new TrieNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

bool search(TrieNode* root, const string& word) {
    TrieNode* current = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (!current->children[index]) return false;
        current = current->children[index];
    }
    return current->isEndOfWord;
}

int main() {
    TrieNode* root = new TrieNode();

    insert(root, "hello");
    insert(root, "world");

    cout << "Search 'hello': " << (search(root, "hello") ? "Found" : "Not Found") << endl;
    cout << "Search 'world': " << (search(root, "world") ? "Found" : "Not Found") << endl;
    return 0;
}