#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size for the arrays

int heights[MAX_SIZE]; // Array to store the heights
int result[MAX_SIZE];  // Array to store the output
int stack[MAX_SIZE];   // Array to simulate the stack
int stackTop;          // Variable to keep track of the top of the stack

// Function to find the number of visible people to the right
void findVisiblePeople(int n) {
    stackTop = -1; // Initialize the stack to be empty

    // Traverse the heights array from right to left
    for (int i = n - 1; i >= 0; --i) {
        int count = 0;
        // Pop from the stack while the current person is taller than stack's top
        while (stackTop != -1 && heights[i] > heights[stack[stackTop]]) {
            stackTop--; // Pop the stack
            count++;    // The person at i can see the person we just popped
        }
        // If the stack is not empty, the person can also see the person at stack's top
        if (stackTop != -1) {
            count++;
        }
        result[i] = count; // Store the count for this person

        // Push the current person onto the stack
        stack[++stackTop] = i;
    }
}

int main() {
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    if (n > MAX_SIZE) {
        cout << "Number of people exceeds maximum allowed size." << endl;
        return 1;
    }

    cout << "Enter the heights of the people: ";
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    // Find the number of visible people to the right
    findVisiblePeople(n);

    // Output the result
    cout << "Output: ";
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
