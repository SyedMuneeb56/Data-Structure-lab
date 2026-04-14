#include <iostream>
using namespace std;

template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    int maxSize;
    int topIndex;

public:
    myStack(int size) {
        maxSize = size;
        arr = new T[maxSize];
        topIndex = -1;
    }

    ~myStack() {
        delete[] arr;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Stack is Full!" << endl;
        }
        else {
            topIndex++;
            arr[topIndex] = value;
        }
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        else {
            return arr[topIndex--];
        }
    }

    T top() const {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        else {
            return arr[topIndex];
        }
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == maxSize - 1;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
        }
        else {
            cout << "Stack (Top to Bottom): ";
            for (int i = topIndex; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    myStack<int> s(5);

    int choice, value;

    
    for (int i = 0; i < 10; i++) {   
        cout << "\n1.Push  2.Pop  3.Top  4.Display  0.Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting" << endl;
            break;
        }

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            cout << "Popped: " << s.pop() << endl;
            break;

        case 3:
            cout << "Top: " << s.top() << endl;
            break;

        case 4:
            s.display();
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}