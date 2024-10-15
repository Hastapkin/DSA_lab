#include <iostream>
using namespace std;

#define SIZE 5 // Kích thước tối đa của hàng đợi (sử dụng mảng)

// Lớp Queue sử dụng mảng
class Queue {
private:
    int arr[SIZE]; // Mảng để lưu trữ các phần tử của hàng đợi
    int front, rear; // Con trỏ cho phần tử đầu (front) và phần tử cuối (rear)

public:
    // Hàm khởi tạo hàng đợi
    void initializeQueue() {
        front = -1;
        rear = -1;
        cout << "Hàng đợi đã được khởi tạo." << endl;
    }

    // Hàm kiểm tra hàng đợi có rỗng hay không
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    // Hàm kiểm tra hàng đợi có đầy hay không
    bool isFull() {
        return (rear == SIZE - 1);
    }

    // Hàm thêm một phần tử vào hàng đợi (enqueue)
    void enqueue(int val) {
        if (isFull()) {
            cout << "Hàng đợi đã đầy. Không thể thêm phần tử." << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        arr[rear] = val;
        cout << val << " đã được thêm vào hàng đợi." << endl;
    }

    // Hàm loại bỏ một phần tử khỏi hàng đợi (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng. Không có gì để loại bỏ." << endl;
            return;
        }
        cout << arr[front] << " đã được loại khỏi hàng đợi." << endl;
        if (front == rear) {
            // Nếu chỉ còn một phần tử, đặt lại hàng đợi sau khi loại bỏ
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Hàm in ra phần tử đầu (front) và cuối (rear) của hàng đợi
    void printFrontRear() {
        if (isEmpty()) {
            cout << "Hàng đợi rỗng." << endl;
        } else {
            cout << "Phần tử đầu: " << arr[front] << endl;
            cout << "Phần tử cuối: " << arr[rear] << endl;
        }
    }

    // Hàm hiển thị menu và thực hiện các thao tác
    void menu() {
        int choice, value;
        do {
            cout << "\nQueue Operations Menu:\n";
            cout << "1. Initialize Queue\n";
            cout << "2. Enqueue\n";
            cout << "3. Dequeue\n";
            cout << "4. Print Front and Rear\n";
            cout << "5. Check if Queue is Empty\n";
            cout << "6. Check if Queue is Full\n";
            cout << "7. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                initializeQueue();
                break;
            case 2:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 3:
                dequeue();
                break;
            case 4:
                printFrontRear();
                break;
            case 5:
                if (isEmpty())
                    cout << "Queue is empty." << endl;
                else
                    cout << "Queue is not empty." << endl;
                break;
            case 6:
                if (isFull())
                    cout << "Queue is full." << endl;
                else
                    cout << "Queue is not full." << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please choose again." << endl;
            }
        } while (choice != 7);
    }
};

int main() {
    Queue q;
    q.menu();
    return 0;
}