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
public:
    Node* root;

    BST()
    {
        root = NULL;
    }

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

    void insert(int value)
    {
        root = insert(root, value);
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

    void display()
    {
        inorder(root);
    }
};

// Function to check if two BSTs are identical
bool isIdentical(Node* root1, Node* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    return (root1->data == root2->data) &&
        isIdentical(root1->left, root2->left) &&
        isIdentical(root1->right, root2->right);
}

int main()
{
    BST tree1, tree2;

    int n1, n2, value;

    cout << "Enter number of nodes in BST 1: ";
    cin >> n1;

    cout << "Enter elements of BST 1: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> value;
        tree1.insert(value);
    }

    cout << endl;

    cout << "Enter number of nodes in BST 2: ";
    cin >> n2;

    cout << "Enter elements of BST 2: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> value;
        tree2.insert(value);
    }

    cout << endl;

    cout << "BST 1 (Inorder): ";
    tree1.display();
    cout << endl;

    cout << "BST 2 (Inorder): ";
    tree2.display();
    cout << endl;

    if (isIdentical(tree1.root, tree2.root))
        cout << "Both BSTs are identical." << endl;
    else
        cout << "Both BSTs are not identical." << endl;

    return 0;
}
