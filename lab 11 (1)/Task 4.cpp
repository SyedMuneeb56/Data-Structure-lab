#include <iostream>
#include <stack>   // stack library for DFS
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

// Function for Iterative DFS Traversal
void DFS(Node* root)
{
    // Check if tree is empty
    if (root == NULL)
    {
        cout << "Tree is empty";
        return;
    }

    // Create stack of node pointers
    stack<Node*> s;

    // Push root node first
    s.push(root);

    cout << "DFS Traversal: ";

    // Repeat until stack becomes empty
    while (!s.empty())
    {
        // Take top node from stack
        Node* current = s.top();

        // Remove node from stack
        s.pop();

        // Print node data
        cout << current->data << " ";

        // Push right child first
        // So left child is processed first
        if (current->right != NULL)
        {
            s.push(current->right);
        }

        // Push left child second
        if (current->left != NULL)
        {
            s.push(current->left);
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

   
    DFS(root);

    return 0;
}

/* Lab Questions
1. Which data structure is used in DFS?

Stack data structure is used in DFS.

2. Why do we push the right child before the left child?

Because stack follows LIFO (Last In First Out).
If we push right child first, then left child stays on top and is processed first.

3. How is DFS different from BFS?
DFS goes deep into one side first before backtracking.
BFS visits nodes level by level.

4. Can recursive preorder traversal be considered a form of DFS? Explain briefly.

Yes, recursive preorder traversal is a type of DFS because it visits nodes deeply from root to left and right before backtracking.
*/