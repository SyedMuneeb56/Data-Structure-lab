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
        else
            node->right = insert(node->right, value);

        return node;
    }

    Node* findMin(Node* node)
    {
        while (node->left != NULL)
            node = node->left;

        return node;
    }

    Node* deleteNode(Node* node, int value)
    {
        if (node == NULL)
            return NULL;

        if (value < node->data)
            node->left = deleteNode(node->left, value);

        else if (value > node->data)
            node->right = deleteNode(node->right, value);

        else
        {
            // Node with no child
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }

            
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

            
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    void inorder(Node* node)
    {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST()
    {
        root = NULL;
    }

    void insertValue(int value)
    {
        root = insert(root, value);
    }

    void deleteValue(int value)
    {
        root = deleteNode(root, value);
    }

    void displayInorder()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    BST tree;

    
    tree.insertValue(50);
    tree.insertValue(30);
    tree.insertValue(70);
    tree.insertValue(20);
    tree.insertValue(40);
    tree.insertValue(60);
    tree.insertValue(80);

    cout << "After Insertion: ";
    tree.displayInorder();

    
    tree.deleteValue(70);

    cout << "After Deletion: ";
    tree.displayInorder();

    return 0;
}