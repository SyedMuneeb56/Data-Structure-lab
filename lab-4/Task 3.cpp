#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int frontIndex, rearIndex;

public:
    Queue() {
        frontIndex = 0;
        rearIndex = -1;
    }

    
    bool isEmpty() {
        return (rearIndex < frontIndex);
    }

    
    void enqueue(int value) {
        arr[++rearIndex] = value;
    }

    
    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        return arr[frontIndex++];
    }

   
    int front() {
        if (isEmpty()) {
            return -1;
        }
        return arr[frontIndex];
    }

   
    int size() {
        return (rearIndex - frontIndex + 1);
    }

    
    void display() {
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int n, value, k;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter queue elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }

    cout << "Enter value of K: ";
    cin >> k;

    cout << "Original Queue: ";
    q.display();

    
    if (k <= 1 || k > q.size()) {
        cout << "No change needed." << endl;
        cout << "Output Queue: ";
        q.display();
        return 0;
    }

    
    int stack[100], top = -1;

    for (int i = 0; i < k; i++) {
        stack[++top] = q.dequeue();
    }

    
    while (top != -1) {
        q.enqueue(stack[top--]);
    }

    
    int remaining = q.size() - k;
    for (int i = 0; i < remaining; i++) {
        q.enqueue(q.dequeue());
    }

    cout << "Output Queue: ";
    q.display();

    return 0;
}