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
    virtual void display() = 0;
    virtual T getMin() const = 0;
};

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T arr[100];      
    T minArr[100];  
    int topIndex;
    int minTop;

public:
    myStack() {
        topIndex = -1;
        minTop = -1;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }

        topIndex++;
        arr[topIndex] = value;

        if (minTop == -1 || value <= minArr[minTop]) {
            minTop++;
            minArr[minTop] = value;
        }

        cout << "Pushed: " << value << endl;
    }

   
    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }

        T value = arr[topIndex];

        
        if (value == minArr[minTop]) {
            minTop--;
        }

        topIndex--;
        return value;
    }

   
    T top() const {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[topIndex];
    }

    
    bool isEmpty() const {
        return (topIndex == -1);
    }

   
    bool isFull() const {
        return (topIndex == 99);
    }

    
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }

        cout << "Stack elements: ";
        for (int i = topIndex; i >= 0; i--) {   
            cout << arr[i] << " ";
        }
        cout << endl;
    }

   
    T getMin() const {
        if (minTop == -1) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return minArr[minTop];
    }
};

// Main function
int main() {
    myStack<int> s;
    int choice, value;

    for (;;) {   
        cout << "\n STACK MENU \n";
        cout << "1. Push element" << endl;
        cout << "2. Pop element" << endl;
        cout << "3. Show top element" << endl;
        cout << "4. Check if empty" << endl;
        cout << "5. Check if full" << endl;
        cout << "6. Display stack" << endl;
        cout << "7. Show minimum element" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
        }
        else if (choice == 2) {
            int x = s.pop();
            if (x != -1)
                cout << "Popped: " << x << endl;
        }
        else if (choice == 3) {
            cout << "Top element: " << s.top() << endl;
        }
        else if (choice == 4) {
            if (s.isEmpty())
                cout << "Stack is empty" << endl;
            else
                cout << "Stack is not empty" << endl;
        }
        else if (choice == 5) {
            if (s.isFull())
                cout << "Stack is full" << endl;
            else
                cout << "Stack is not full" << endl;
        }
        else if (choice == 6) {
            s.display();
        }
        else if (choice == 7) {
            cout << "Minimum element: " << s.getMin() << endl;
        }
        else if (choice == 8) {
            cout << "Exiting program" << endl;
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}