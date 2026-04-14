#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
};

node* head = nullptr;

void createnode(int value) {
    node* newnode = new node();
    newnode->data = value;
    newnode->next = nullptr;

    if (head == nullptr) {
        head = newnode;
    } else {
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display() {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    createnode(10);
    createnode(20);
    createnode(30);

    display();

    return 0;
}