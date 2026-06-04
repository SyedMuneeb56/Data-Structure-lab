#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:
    Node* root;

    Node* insert(Node* node, int value)
    {
        if (node == NULL)
            return new Node(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        // Duplicate values are ignored

        return node;
    }

    void inorder(Node* node)
    {
        if (node != NULL)
        {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node)
    {
        if (node != NULL)
        {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node)
    {
        if (node != NULL)
        {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    bool search(Node* node, int key)
    {
        if (node == NULL)
            return false;

        if (node->data == key)
            return true;

        if (key < node->data)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    void inorder()
    {
        inorder(root);
    }

    void preorder()
    {
        preorder(root);
    }

    void postorder()
    {
        postorder(root);
    }

    bool search(int key)
    {
        return search(root, key);
    }
};

int main()
{
    BST tree;

    int n, value, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        tree.insert(value);
    }

    cout << endl;

    cout << "Inorder Traversal: ";
    tree.inorder();
    cout << endl;

    cout << "Preorder Traversal: ";
    tree.preorder();
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorder();
    cout << endl;

    cout << endl;
    cout << "Enter key to search: ";
    cin >> key;

    if (tree.search(key))
        cout << "Key found in BST" << endl;
    else
        cout << "Key not found in BST" << endl;

    return 0;
}
