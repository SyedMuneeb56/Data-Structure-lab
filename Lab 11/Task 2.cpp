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

        return node;
    }

    Node* findMin(Node* node)
    {
        while (node->left != NULL)
            node = node->left;

        return node;
    }

    Node* deleteNode(Node* node, int key)
    {
        if (node == NULL)
            return NULL;

        if (key < node->data)
        {
            node->left = deleteNode(node->left, key);
        }
        else if (key > node->data)
        {
            node->right = deleteNode(node->right, key);
        }
        else
        {
            // Case 1: Leaf Node
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }

            // Case 2: One Child
            else if (node->left == NULL)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3: Two Children
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

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

public:
    BST()
    {
        root = NULL;
    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    void deleteValue(int key)
    {
        root = deleteNode(root, key);
    }

    void inorder()
    {
        inorder(root);
    }
};

int main()
{
    BST tree;

    int n, value, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        tree.insert(value);
    }

    cout << endl;
    cout << "Inorder Traversal Before Deletion: ";
    tree.inorder();
    cout << endl;

    cout << "Enter value to delete: ";
    cin >> key;

    tree.deleteValue(key);

    cout << "Inorder Traversal After Deletion: ";
    tree.inorder();
    cout << endl;

    return 0;
}
