#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Linked List Node Structure
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

// Function Prototypes
void addTwoNumbersMenu();
void copyRandomListMenu();
void swapNodesMenu();
void removeNthFromEndMenu();
void separateOddEvenMenu();
void divideLinkedListPartsMenu();
void removeZeroSumConsecutiveMenu();
void generateRandomListMenu();
void displayMenu();

// Helper Functions
void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "null" << endl;
}

// Add Two Numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }

    return dummy->next;
}

// Copy List with Random Pointers
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    unordered_map<Node*, Node*> map;
    Node* current = head;

    while (current) {
        map[current] = new Node(current->val);
        current = current->next;
    }

    current = head;
    while (current) {
        map[current]->next = map[current->next];
        map[current]->random = map[current->random];
        current = current->next;
    }

    return map[head];
}

// Swap Nodes in a Linked List
ListNode* swapNodes(ListNode* head, int k) {
    ListNode* first = head;
    ListNode* second = head;
    ListNode* fast = head;

    for (int i = 1; i < k; i++) {
        fast = fast->next;
    }

    first = fast;

    while (fast->next != nullptr) {
        fast = fast->next;
        second = second->next;
    }

    swap(first->val, second->val);

    return head;
}

// Remove the N-th Node from the End of a List
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* first = dummy;
    ListNode* second = dummy;

    for (int i = 1; i <= n + 1; i++) {
        first = first->next;
    }

    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    second->next = second->next->next;
    return dummy->next;
}

// Separate Odd and Even Nodes in a Linked List
ListNode* separateOddEven(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;

    return head;
}

// Divide a Linked List into K Parts
vector<ListNode*> divideLinkedListParts(ListNode* head, int k) {
    vector<ListNode*> result(k, nullptr);
    ListNode* curr = head;
    int n = 0;

    while (curr) {
        n++;
        curr = curr->next;
    }

    int partSize = n / k;
    int extra = n % k;

    curr = head;
    for (int i = 0; i < k && curr; i++) {
        result[i] = curr;
        int currPartSize = partSize + (extra > 0 ? 1 : 0);
        extra--;
        for (int j = 1; j < currPartSize; j++) {
            curr = curr->next;
        }
        ListNode* next = curr->next;
        curr->next = nullptr;
        curr = next;
    }

    return result;
}

// Remove Zero-Sum Consecutive Nodes from a Linked List
ListNode* removeZeroSumConsecutive(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    unordered_map<int, ListNode*> prefixMap;
    int sum = 0;
    for (ListNode* curr = dummy; curr != nullptr; curr = curr->next) {
        sum += curr->val;
        prefixMap[sum] = curr;
    }

    sum = 0;
    for (ListNode* curr = dummy; curr != nullptr; curr = curr->next) {
        sum += curr->val;
        curr->next = prefixMap[sum]->next;
    }

    return dummy->next;
}

// Generate Random List
ListNode* generateRandomList(int minRange, int maxRange, int sizeMin, int sizeMax) {
    srand(time(0));
    int listSize = rand() % (sizeMax - sizeMin + 1) + sizeMin;

    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    for (int i = 0; i < listSize; i++) {
        int value = rand() % (maxRange - minRange + 1) + minRange;
        current->next = new ListNode(value);
        current = current->next;
    }

    return dummy->next;
}

// Menu Options for Each Problem
void addTwoNumbersMenu() {
    cout << "Example 1: Adding 243 + 564\n";
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = addTwoNumbers(l1, l2);
    cout << "Result: ";
    printList(result); // Expected Output: 7 -> 0 -> 8 -> null
}

void copyRandomListMenu() {
    cout << "Copying a List with Random Pointers\n";
    Node* head = new Node(1);
    head->next = new Node(2);
    head->random = head->next;
    head->next->random = head;

    Node* copiedList = copyRandomList(head);

    cout << "Original List Value: " << head->val << " Copied List Value: " << copiedList->val << endl;
}

void swapNodesMenu() {
    cout << "Example 3: Swapping Nodes\n";
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    ListNode* result = swapNodes(head, k);
    cout << "Swapped Result: ";
    printList(result); // Expected Output: 1 -> 4 -> 3 -> 2 -> 5 -> null
}

void removeNthFromEndMenu() {
    cout << "Removing the N-th Node from the End\n";
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;
    ListNode* result = removeNthFromEnd(head, n);
    cout << "Result: ";
    printList(result); // Expected Output: 1 -> 2 -> 3 -> 5 -> null
}

void separateOddEvenMenu() {
    cout << "Separating Odd and Even Nodes\n";
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* result = separateOddEven(head);
    cout << "Result: ";
    printList(result); // Expected Output: 1 -> 3 -> 5 -> 2 -> 4 -> null
}

void divideLinkedListPartsMenu() {
    cout << "Dividing Linked List into Parts\n";
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 3;
    vector<ListNode*> parts = divideLinkedListParts(head, k);

    cout << "Result:\n";
    for (int i = 0; i < parts.size(); i++) {
        printList(parts[i]);
    }
}

void removeZeroSumConsecutiveMenu() {
    cout << "Removing Zero-Sum Consecutive Nodes\n";
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);

    ListNode* result = removeZeroSumConsecutive(head);
    cout << "Result: ";
    printList(result); // Expected Output: 3 -> 1 -> null
}

void generateRandomListMenu() {
    cout << "Generating Random List\n";
    ListNode* randomList = generateRandomList(-99, 99, 39, 59);
    printList(randomList);
}

// Main Menu for Selecting Tasks
void displayMenu() {
    int choice = 0;

    do {
        cout << "\n---- In-Class Exercise Menu ----\n";
        cout << "1. Add Two Numbers\n";
        cout << "2. Copy List with Random Pointers\n";
        cout << "3. Swap Nodes in a Linked List\n";
        cout << "4. Remove the N-th Node from the End of a List\n";
        cout << "5. Separate Odd and Even Nodes in a Linked List\n";
        cout << "6. Divide a Linked List into Parts\n";
        cout << "7. Remove Zero-Sum Consecutive Nodes\n";
        cout << "8. Generate a Random List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTwoNumbersMenu();
                break;
            case 2:
                copyRandomListMenu();
                break;
            case 3:
                swapNodesMenu();
                break;
            case 4:
                removeNthFromEndMenu();
                break;
            case 5:
                separateOddEvenMenu();
                break;
            case 6:
                divideLinkedListPartsMenu();
                break;
            case 7:
                removeZeroSumConsecutiveMenu();
                break;
            case 8:
                generateRandomListMenu();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

int main() {
    displayMenu();
    return 0;
}
