#include <iostream>
#include <string>
using namespace std;

class myCarStack {
private:
    string arr[8];   
    int topIndex;

public:
    myCarStack() {
        topIndex = -1;
    }

    
    void push(string car) {
        if (isFull()) {
            cout << "Parking is FULL!" << endl;
            return;
        }
        topIndex++;
        arr[topIndex] = car;
        cout << "Car parked: " << car << endl;
    }

    
    string pop() {
        if (isEmpty()) {
            cout << "Parking is EMPTY!" << endl;
            return "";
        }
        string car = arr[topIndex];
        topIndex--;
        return car;
    }

    
    string top() {
        return isEmpty() ? "" : arr[topIndex];
    }

    
    bool isEmpty() {
        return (topIndex == -1);
    }

    
    bool isFull() {
        return (topIndex == 7);
    }

    
    void display() {
        if (isEmpty()) {
            cout << "No cars parked." << endl;
            return;
        }
        cout << "Cars in parking:" << endl;
        for (int i = topIndex; i >= 0; i--)
            cout << arr[i] << endl;
    }

  
    int count() {
        return topIndex + 1;
    }

    
    bool search(string car) {
        for (int i = 0; i <= topIndex; i++)
            if (arr[i] == car)
                return true;
        return false;
    }

    
    void removeCar(string car) {
        if (isEmpty()) {
            cout << "Parking is empty!" << endl;
            return;
        }

        myCarStack tempStack;
        bool found = false;

        
        while (!isEmpty()) {
            string topCar = pop();
            if (topCar == car) {
                cout << "Car removed: " << car << endl;
                found = true;
                break;
            }
            else {
                tempStack.push(topCar);
            }
        }

        
        while (!tempStack.isEmpty())
            push(tempStack.pop());

        if (!found)
            cout << "Car not found!" << endl;
    }
};

int main() {
    myCarStack parking;
    bool running = true;

    while (running) {
        cout << endl;
        cout << "===== PARKING SYSTEM =====" << endl;
        cout << "1. Park new car" << endl;
        cout << "2. Remove car" << endl;
        cout << "3. Show all cars" << endl;
        cout << "4. Show total cars" << endl;
        cout << "5. Search car" << endl;
        cout << "6. Show top car" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: ";

        int choice;
        cin >> choice;
        cin.ignore(); 

        string car;

        switch (choice) {
        case 1:
            cout << "Enter car number: ";
            getline(cin, car);
            parking.push(car);
            break;

        case 2:
            cout << "Enter car number to remove: ";
            getline(cin, car);
            parking.removeCar(car);
            break;

        case 3:
            parking.display();
            break;

        case 4:
            cout << "Total cars: " << parking.count() << endl;
            break;

        case 5:
            cout << "Enter car number to search: ";
            getline(cin, car);
            if (parking.search(car))
                cout << "Car found!" << endl;
            else
                cout << "Car not found!" << endl;
            break;

        case 6:
            car = parking.top();
            if (!car.empty())
                cout << "Top car: " << car << endl;
            else
                cout << "No cars parked." << endl;
            break;

        case 7:
            cout << "Exiting..." << endl;
            running = false;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}