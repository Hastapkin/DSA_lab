#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100]; // stack elements (maximum size 100)
    int top;      // top element

public:
    // initialize the stack
    Stack() {
        top = -1; // Empty stack
    }

    // the stack is empty or not
    bool isEmpty() {
        return (top == -1);
    }

    // push an element
    void push(int value) {
        if (top < 99) { 
            arr[++top] = value;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    // pop an element
    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        } else {
            cout << "Stack underflow!" << endl;
            return -1; 
        }
    }

    // get the top element of the stack without removing
    int peek() {
        if (!isEmpty()) {
            return arr[top];
        } else {
            return -1; // if emty
        }
    }

    // print the stack elements
    void printStack() {
        cout << "STACK = < ";
        for (int i = 0; i <= top; ++i) {
            cout << arr[i] << " ";
        }
        cout << ">\n";
    }
};

// status of the towers
void printTowers(Stack towers[]) {
    for (char tower = 'A'; tower <= 'C'; ++tower) {
        cout << tower << " Tower\n";
        towers[tower - 'A'].printStack();
        cout << "==========================\n";
    }
}

// move a disk between two towers
void moveDisk(Stack towers[], char from, char to) {
    int disk = towers[from - 'A'].pop();
    towers[to - 'A'].push(disk);
    cout << "Move disk " << disk << " from " << from << " to " << to << endl;
    printTowers(towers);
}

// solve the Tower of Hanoi
void solveHanoi(int n, Stack towers[], char from, char to, char aux) {
    if (n == 1) {
        moveDisk(towers, from, to);
        return;
    }
    solveHanoi(n - 1, towers, from, aux, to);
    moveDisk(towers, from, to);
    solveHanoi(n - 1, towers, aux, to, from);
}

int main() {
    int numDisks;
    cout << "Enter the number of disks: ";
    cin >> numDisks;

    Stack towers[3]; 

    // Initialize the first tower 
    for (int i = numDisks; i >= 1; --i) {
        towers[0].push(i);
    }

    // status of the towers
    cout << "=========== Demo Stack ===========\n";
    cout << "0. Creating Tower.\n";
    printTowers(towers);
    cout << "==================================\n";

    // Tower of Hanoi from tower A to C using B 
    solveHanoi(numDisks, towers, 'A', 'C', 'B');

    // status of the towers
    cout << "Finished status:\n";
    printTowers(towers);

    return 0;
}