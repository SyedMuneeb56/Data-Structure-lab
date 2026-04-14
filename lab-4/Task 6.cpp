#include <iostream>
using namespace std;

class PackageQueue {
private:
    int ids[100];
    string addresses[100];
    int startTimes[100];
    int endTimes[100];
    int frontIndex, rearIndex;

public:
    PackageQueue() {
        frontIndex = 0;
        rearIndex = -1;
    }

    bool isEmpty() {
        return (rearIndex < frontIndex);
    }

    bool isFull() {
        return (rearIndex == 99);
    }

    void enqueue(int id, string address, int startTime, int endTime) {
        if (isFull()) {
            cout << "Queue Full!" << endl;
            return;
        }
        rearIndex++;
        ids[rearIndex] = id;
        addresses[rearIndex] = address;
        startTimes[rearIndex] = startTime;
        endTimes[rearIndex] = endTime;
        cout << "Package Added: " << id << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No packages in queue!" << endl;
            return;
        }
        cout << "Delivered Package: " << ids[frontIndex] << endl;
        frontIndex++;
    }

    void front() {
        if (isEmpty()) {
            cout << "No packages in queue!" << endl;
            return;
        }
        cout << "Front Package ID: " << ids[frontIndex]
            << ", Address: " << addresses[frontIndex]
            << ", Time Window: " << startTimes[frontIndex] << "-" << endTimes[frontIndex]
            << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending packages" << endl;
            return;
        }
        cout << "Packages in Queue:" << endl;
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << "ID: " << ids[i]
                << ", Address: " << addresses[i]
                << ", Time Window: " << startTimes[i] << "-" << endTimes[i] << endl;
        }
    }

    void timeToDeliver(int currentTime) {
        while (!isEmpty()) {
            if (currentTime >= startTimes[frontIndex] && currentTime <= endTimes[frontIndex]) {
                cout << "Package " << ids[frontIndex] << " can be delivered now." << endl;
                break;
            }
            else if (currentTime > endTimes[frontIndex]) {
                cout << "Package " << ids[frontIndex] << " expired, skipping." << endl;
                frontIndex++;
            }
            else {
                cout << "Next package not yet deliverable." << endl;
                break;
            }
        }
    }
};

int main() {
    PackageQueue q;
    int choice;
    int id, startTime, endTime;
    string address;
    int currentTime;

    for (int i = 0; ; i++) {
        cout << endl;
        cout << "1. Add Package" << endl;
        cout << "2. Deliver Front Package" << endl;
        cout << "3. Check Front Package" << endl;
        cout << "4. Display Packages" << endl;
        cout << "5. Check Delivery Time" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Package ID: ";
            cin >> id;
            cout << "Enter Address: ";
            cin >> address;
            cout << "Enter Start Time: ";
            cin >> startTime;
            cout << "Enter End Time: ";
            cin >> endTime;
            q.enqueue(id, address, startTime, endTime);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.front();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Enter Current Time: ";
            cin >> currentTime;
            q.timeToDeliver(currentTime);
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid choice" << endl;
        }
    }
}