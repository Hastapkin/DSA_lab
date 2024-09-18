#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Find the Middle Node of a Linked List
Node* findMiddle(Node* head) {
    if (head == nullptr)
        return nullptr;
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Detect a Cycle in a Linked List using Floyd’s Cycle Detection Algorithm
bool detectCycle(Node* head) {
    if (head == nullptr)
        return false;
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

// Merge Two Sorted Linked Lists
Node* mergeSortedList(Node* a, Node* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;
    Node* head = nullptr;
    if (a->data <= b->data) {
        head = a;
        a = a->next;
    } else {
        head = b;
        b = b->next;
    }
    Node* current = head;
    while (a != nullptr && b != nullptr) {
        if (a->data <= b->data) {
            current->next = a;
            a = a->next;
        } else {
            current->next = b;
            b = b->next;
        }
        current = current->next;
    }
    current->next = (a != nullptr) ? a : b;
    return head;
}

// Display Linked List
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Find the Intersection of Two Linked Lists
Node* getIntersectionNode(Node* head1, Node* head2) {
    while (head2 != nullptr) {
        Node* temp = head1;
        while (temp) {
            if (temp == head2)
                return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    return nullptr;
}

// Reverse a Linked List
Node* reverseList(Node* head) {
    Node* curr = head;
    Node* prev = nullptr;
    Node* next;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Eliminate Duplicates from a Sorted Linked List
Node* removeDuplicates(Node* head) {
    unordered_set<int> st;
    Node* new_head = nullptr;
    Node* tail = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        if (st.find(curr->data) == st.end()) {
            Node* new_node = new Node(curr->data);
            if (new_head == nullptr) {
                new_head = new_node;
                tail = new_head;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
            st.insert(curr->data);
        }
        curr = curr->next;
    }
    return new_head;
}

// Check if a Linked List is a Palindrome
bool isIdentical(Node* n1, Node* n2) {
    while (n1 && n2) {
        if (n1->data != n2->data)
            return false;
        n1 = n1->next;
        n2 = n2->next;
    }
    return true;
}

bool isPalindrome(Node* head) {
    if (!head || !head->next)
        return true;
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* head2 = reverseList(slow->next);
    slow->next = nullptr;
    bool result = isIdentical(head, head2);
    slow->next = reverseList(head2);
    return result;
}

// Search for a value X in the Linked List
Node* searchKey(Node* head, int key) {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data == key)
            return curr;
        curr = curr->next;
    }
    return nullptr;
}

// Driver code - Main Menu
int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Find Middle of Linked List\n";
        cout << "2. Detect Cycle in Linked List\n";
        cout << "3. Merge Two Sorted Linked Lists\n";
        cout << "4. Find the Intersection of Two Linked Lists\n";
        cout << "5. Reverse a Linked List\n";
        cout << "6. Eliminate Duplicates from a Sorted Linked List\n";
        cout << "7. Check if a Linked List is a Palindrome\n";
        cout << "8. Search for a value in the Linked List\n";
        cout << "0. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            Node* n1 = new Node(10);
            Node* n2 = new Node(20);
            Node* n3 = new Node(30);
            head1 = n1;
            head1->next = n2;
            n2->next = n3;
            Node* middle = findMiddle(head1);
            if (middle != nullptr) {
                cout << "The middle node is: " << middle->data << endl;
            }
            break;
        }
        case 2: {
            if (detectCycle(head1)) {
                cout << "Cycle detected in Linked List 1" << endl;
            } else {
                cout << "No cycle in Linked List 1" << endl;
            }
            break;
        }
        case 3: {
            Node* a = new Node(1);
            a->next = new Node(5);
            a->next->next = new Node(8);
            Node* b = new Node(2);
            b->next = new Node(4);
            b->next->next = new Node(9);
            cout << "Merging Linked List 1 and Linked List 2...\n";
            Node* mergedList = mergeSortedList(a, b);
            displayList(mergedList);
            break;
        }
        case 4: {
            Node* n1 = new Node(3);
            Node* n2 = new Node(6);
            head1 = n1;
            head1->next = n2;
            Node* m1 = new Node(3);
            Node* m2 = new Node(7);
            head2 = m1;
            head2->next = m2;
            Node* intersection = getIntersectionNode(head1, head2);
            if (intersection != nullptr) {
                cout << "Intersection found at node with value: " << intersection->data << endl;
            } else {
                cout << "No intersection found.\n";
            }
            break;
        }
        case 5: {
            cout << "Reversing the Linked List...\n";
            head1 = reverseList(head1);
            displayList(head1);
            break;
        }
        case 6: {
            cout << "Eliminating duplicates from the Linked List...\n";
            head1 = removeDuplicates(head1);
            displayList(head1);
            break;
        }
        case 7: {
            if (isPalindrome(head1)) {
                cout << "The linked list is a palindrome\n";
            } else {
                cout << "The linked list is not a palindrome\n";
            }
            break;
        }
        case 8: {
            int key;
            cout << "Enter the value to search: ";
            cin >> key;
            Node* foundNode = searchKey(head1, key);
            if (foundNode != nullptr) {
                cout << "Node with value " << key << " found at address: " << foundNode << endl;
            } else {
                cout << "Node with value " << key << " not found.\n";
            }
            break;
        }
        case 0: {
            cout << "Exiting...\n";
            break;
        }
        default: {
            cout << "Invalid choice! Please try again.\n";
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
