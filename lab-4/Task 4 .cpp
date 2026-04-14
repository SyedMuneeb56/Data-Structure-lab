#include <iostream>
using namespace std;

class TicketQueue {
private:
    int arr[100];
    int frontIndex, rearIndex;

public:
    TicketQueue() {
        frontIndex = 0;
        rearIndex = -1;
    }

    bool isEmpty() {
        return (rearIndex < frontIndex);
    }

    bool isFull() {
        return (rearIndex == 99);
    }

    void enqueue(int ticket_id) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }
        arr[++rearIndex] = ticket_id;
        cout << "Ticket Added: " << ticket_id << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "No tickets available" << endl;
            return -1;
        }
        return arr[frontIndex++];
    }

    int front() {
        if (isEmpty()) {
            cout << "No tickets available" << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending tickets" << endl;
            return;
        }
        cout << "Pending Tickets: ";
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    TicketQueue q;
    int choice, id;

    for (int i = 0; i < 5 ; i++) {
        cout << endl;
        cout << "1. Add Ticket" << endl;
        cout << "2. Resolve Ticket" << endl;
        cout << "3. Next Ticket" << endl;
        cout << "4. Display Tickets" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter 4-digit Ticket ID: ";
            cin >> id;
            q.enqueue(id);
            break;

        case 2:
            cout << "Resolved Ticket: " << q.dequeue() << endl;
            break;

        case 3:
            cout << "Next Ticket: " << q.front() << endl;
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