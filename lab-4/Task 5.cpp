#include <iostream>
using namespace std;

class PrintQueue {
private:
    string arr[100];
    int frontIndex, rearIndex;

public:
    PrintQueue() {
        frontIndex = 0;
        rearIndex = -1;
    }

    bool isEmpty() {
        return (rearIndex < frontIndex);
    }

    bool isFull() {
        return (rearIndex == 99);
    }

    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }
        arr[++rearIndex] = name;
        cout << "Added: " << name << endl;
    }

    string dequeue() {
        if (isEmpty()) {
            cout << "No documents to print" << endl;
            return "";
        }
        return arr[frontIndex++];
    }

    string front() {
        if (isEmpty()) {
            cout << "No documents available" << endl;
            return "";
        }
        return arr[frontIndex];
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending documents" << endl;
            return;
        }
        cout << "Pending Documents: ";
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PrintQueue q;
    int choice;
    string name;

    for (int i = 0; ; i++) {
        cout << endl;
        cout << "1. Add Document" << endl;
        cout << "2. Print Document" << endl;
        cout << "3. Front Document" << endl;
        cout << "4. Display Documents" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter document name: ";
            cin >> name;
            q.enqueue(name);
            break;

        case 2:
            cout << "Printing: " << q.dequeue() << endl;
            break;

        case 3:
            cout << "Front Document: " << q.front() << endl;
            break;

        case 4:
            q.display();
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}