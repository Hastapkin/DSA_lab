#include <iostream>
using namespace std;

class Browser {
private:
    const int MAX_SIZE = 10; 
    char backStack[10][10]; 
    char forwardStack[10][10]; 
    int backTop;              
    int forwardTop;           
    char currentUrl[10];     

public:
    // emty stack
    Browser() {
        backTop = -1; 
        forwardTop = -1; 
        currentUrl[0] = '\0'; 
    }

    // visit a new URL
    void visit(const char url[]) {
        if (currentUrl[0] != '\0') {
            backTop++;
            copyUrl(currentUrl, backStack[backTop]);
        }
        // update the URL
        copyUrl(url, currentUrl);
        // clear the forward stack
        forwardTop = -1;
        cout << "Visited: " << currentUrl << endl;
    }

    // go back to the previous URL
    void back() {
        if (backTop == -1) {
            // no URL in the back stack
            cout << "No previous URL to go back to." << endl;
            return;
        }
        // push the current URL onto the forward stack
        forwardTop++;
        copyUrl(currentUrl, forwardStack[forwardTop]);
        // pop the top URL from the back stack and set it as the current URL
        copyUrl(backStack[backTop], currentUrl);
        backTop--;
        cout << "Went back to: " << currentUrl << endl;
    }

    // go forward to the next URL
    void forward() {
        if (forwardTop == -1) {
            // no next URL in the forward stack
            cout << "No next URL to go forward to." << endl;
            return;
        }
        // push the current URL onto the back stack
        backTop++;
        copyUrl(currentUrl, backStack[backTop]);
        // pop the top URL from the forward stack and set it as the current URL
        copyUrl(forwardStack[forwardTop], currentUrl);
        forwardTop--;
        cout << "Went forward to: " << currentUrl << endl;
    }

    // copy one URL to another
    void copyUrl(const char source[], char destination[]) {
        int i = 0;
        while (source[i] != '\0') {
            destination[i] = source[i];
            i++;
        }
        destination[i] = '\0';
    }

    // display the current
 void displayCurrentUrl() const {
        if (currentUrl[0] == '\0') {
            cout << "No current URL." << endl;
        } else {
            cout << "Current URL: " << currentUrl << endl;
        }
    }
};

// display the menu
void displayMenu() {
    cout << "\nBrowser Navigation Simulation Menu:\n";
    cout << "1. Visit a new URL\n";
    cout << "2. Go back to the previous URL\n";
    cout << "3. Go forward to the next URL\n";
    cout << "4. Display current URL\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Browser browser;
    int choice;
    char url[100];

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // To clear the newline character from the input buffer

        switch (choice) {
        case 1:
            cout << "Enter the URL to visit: ";
            cin.getline(url, 100);
            browser.visit(url);
            break;
        case 2:
            browser.back();
            break;
        case 3:
            browser.forward();
            break;
        case 4:
            browser.displayCurrentUrl();
            break;
        case 5:
            cout << "Exiting the browser simulation." << endl;
            break;
        default:
            cout << "Invalid choice! Please choose again." << endl;
        }
    } while (choice != 5);

    return 0;
}