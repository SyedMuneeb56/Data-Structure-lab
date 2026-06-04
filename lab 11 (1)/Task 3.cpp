#include <iostream>
#include <queue>   // queue library for BFS
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

// Function for BFS / Level Order Traversal
void BFS(Node* root)
{
    // If tree is empty
    if (root == NULL)
    {
        cout << "Tree is empty";
        return;
    }

    // Create queue of Node pointers
    queue<Node*> q;

    // First insert root node
    q.push(root);

    cout << "BFS / Level-Order Traversal: ";

    // Repeat until queue becomes empty
    while (!q.empty())
    {
        // Take front node from queue
        Node* current = q.front();

        // Remove it from queue
        q.pop();

        // Print current node data
        cout << current->data << " ";

        // Insert left child into queue
        if (current->left != NULL)
        {
            q.push(current->left);
        }

        // Insert right child into queue
        if (current->right != NULL)
        {
            q.push(current->right);
        }
    }
}

int main()
{
    // Creating tree manually

    Node* root = new Node(40);

    root->left = new Node(20);
    root->right = new Node(60);

    root->left->left = new Node(10);
    root->left->right = new Node(30);

    root->right->left = new Node(50);
    root->right->right = new Node(70);

    
    BFS(root);

    return 0;
}


/* Lab Questions
1. Which data structure is used in BFS?

Queue data structure is used in BFS.

2. Why does BFS print nodes level by level?

Because queue follows FIFO (First In First Out), so nodes are visited in the same order they are inserted level by level.

3. What is the first node inserted into the queue?
The root node (40) is inserted first.

4. Write the queue contents after printing node 40.

After printing 40, its children are inserted.

Queue contents:

20 60    */