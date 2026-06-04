#include <iostream>
#include <string>
using namespace std;

// BST Node
class BSTNode
{
public:
    int isbn;
    string title;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int i, string t)
    {
        isbn = i;
        title = t;
        left = NULL;
        right = NULL;
    }
};

// Linked List Node
class ListNode
{
public:
    int isbn;
    string title;
    ListNode* next;

    ListNode(int i, string t)
    {
        isbn = i;
        title = t;
        next = NULL;
    }
};

class Library
{
private:
    BSTNode* root;

    // Insert into BST
    BSTNode* insert(BSTNode* node, int isbn, string title)
    {
        if (node == NULL)
            return new BSTNode(isbn, title);

        if (isbn < node->isbn)
            node->left = insert(node->left, isbn, title);
        else if (isbn > node->isbn)
            node->right = insert(node->right, isbn, title);

        return node;
    }

    // Convert BST to Linked List using Inorder Traversal
    void bstToList(BSTNode* node, ListNode*& head, ListNode*& tail)
    {
        if (node == NULL)
            return;

        bstToList(node->left, head, tail);

        ListNode* newNode = new ListNode(node->isbn, node->title);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        bstToList(node->right, head, tail);
    }

public:
    Library()
    {
        root = NULL;
    }

    void insertBook(int isbn, string title)
    {
        root = insert(root, isbn, title);
    }

    ListNode* convertToLinkedList()
    {
        ListNode* head = NULL;
        ListNode* tail = NULL;

        bstToList(root, head, tail);

        return head;
    }

    void printLinkedList(ListNode* head)
    {
        cout << endl;
        cout << "Sorted Book Catalog:" << endl;

        while (head != NULL)
        {
            cout << "ISBN: " << head->isbn
                << " , Title: " << head->title << endl;

            head = head->next;
        }
    }
};

int main()
{
    Library lib;

    int n, isbn;
    string title;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << endl;
        cout << "Enter ISBN: ";
        cin >> isbn;

        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        lib.insertBook(isbn, title);
    }

    ListNode* head = lib.convertToLinkedList();

    lib.printLinkedList(head);

    return 0;
}