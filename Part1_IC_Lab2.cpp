#include <iostream>
using namespace std;

const int MAX = 100; // Maximum size of the stack
int stack[MAX];
int top;

// 1. Function to initialize the stack
void initialize() 
{
    top = -1;
}

// 2. Function to check if the stack is empty. If empty, return true, otherwise return false.
bool isEmpty() 
{
    return top == -1;
}

// 3. Function to check if the stack is full (if applicable). If full, return true, otherwise return false.
bool isFull() 
{
    return top == MAX - 1;
}

// 4. Function to push an element onto the stack.
void push(int element) 
{
    if (isFull()) 
    {
        cout << "Stack is full. Cannot push." << endl;
    } 
    else 
    {
        stack[++top] = element;
        cout << "Pushed " << element << " onto the stack." << endl;
    }
}

// 5. Function to pop an element from the stack.
void pop() 
{
    if (isEmpty()) 
    {
        cout << "Stack is empty. Cannot pop." << endl;
    } 
    else 
    {
        cout << "Popped " << stack[top--] << " from the stack." << endl;
    }
}

// 6. Print the TOP element of the stack.
void printTop() 
{
    if (isEmpty()) 
    {
        cout << "Stack is empty." << endl;
    } 
    else 
    {
        cout << "Top element is: " << stack[top] << endl;
    }
}

// Function to display the stack (from top to bottom)
void displayStack() 
{
    if (isEmpty()) 
    {
        cout << "Stack is empty." << endl;
    } 
    else 
    {
        cout << "Stack elements (from top to bottom): ";
        for (int i = top; i >= 0; i--) 
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

// Main function with a menu to display stack operations
int main() 
{
    int choice, value;
    initialize(); // Initialize the stack

    do 
    {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Check if Stack is Empty\n";
        cout << "2. Check if Stack is Full\n";
        cout << "3. Push\n";
        cout << "4. Pop\n";
        cout << "5. Print Top Element\n";
        cout << "6. Display Stack\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            if (isEmpty()) 
            {
                cout << "Stack is empty." << endl;
            } 
            else 
            {
                cout << "Stack is not empty." << endl;
            }
            break;

        case 2:
            if (isFull()) 
            {
                cout << "Stack is full." << endl;
            } 
            else 
            {
                cout << "Stack is not full." << endl;
            }
            break;

        case 3:
            cout << "Enter value to push: ";
            cin >> value;
            push(value);
            break;

        case 4:
            pop();
            break;

        case 5:
            printTop();
            break;

        case 6:
            displayStack();
            break;

        case 7:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7); // Exit when user chooses option 7

    return 0;
}
