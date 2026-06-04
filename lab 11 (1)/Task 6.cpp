#include <iostream>
#include <stack>
using namespace std;

// Class for expression tree node
class ExprNode
{
public:
    string data;
    ExprNode* left;
    ExprNode* right;

    // Constructor
    ExprNode(string value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to check operator
bool isOperator(string value)
{
    if (value == "+" || value == "-" || value == "*")
    {
        return true;
    }

    return false;
}

// Function to build expression tree from postfix
ExprNode* buildTree(string postfix[], int size)
{
    // Stack for nodes
    stack<ExprNode*> s;

    // Scan postfix expression
    for (int i = 0; i < size; i++)
    {
        string symbol = postfix[i];

        // If operand then push into stack
        if (!isOperator(symbol))
        {
            ExprNode* newNode = new ExprNode(symbol);
            s.push(newNode);
        }

        // If operator
        else
        {
            // Pop two nodes
            ExprNode* rightNode = s.top();
            s.pop();

            ExprNode* leftNode = s.top();
            s.pop();

            // Create operator node
            ExprNode* newNode = new ExprNode(symbol);

            // Link children
            newNode->left = leftNode;
            newNode->right = rightNode;

            // Push back into stack
            s.push(newNode);
        }
    }

    // Final node is root
    return s.top();
}

// Function for infix traversal
void printInfix(ExprNode* root)
{
    if (root == NULL)
    {
        return;
    }

    // Opening bracket
    if (root->left != NULL)
    {
        cout << "(";
    }

    printInfix(root->left);

    cout << root->data;

    printInfix(root->right);

    // Closing bracket
    if (root->right != NULL)
    {
        cout << ")";
    }
}

// Function for prefix traversal
void printPrefix(ExprNode* root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    printPrefix(root->left);
    printPrefix(root->right);
}

// Function for postfix traversal
void printPostfix(ExprNode* root)
{
    if (root == NULL)
    {
        return;
    }

    printPostfix(root->left);
    printPostfix(root->right);

    cout << root->data << " ";
}

// Function to evaluate expression tree
int evaluate(ExprNode* root)
{
    // If operand node
    if (root->left == NULL && root->right == NULL)
    {
        return root->data[0] - '0';
    }

    int leftValue = evaluate(root->left);
    int rightValue = evaluate(root->right);

    // Perform operation
    if (root->data == "+")
    {
        return leftValue + rightValue;
    }

    else if (root->data == "-")
    {
        return leftValue - rightValue;
    }

    else if (root->data == "*")
    {
        return leftValue * rightValue;
    }

    return 0;
}

int main()
{
    // Postfix expression
    string postfix[] = { "3", "5", "+", "8", "2", "-", "*" };

    int size = 7;

    // Build expression tree
    ExprNode* root = buildTree(postfix, size);

    // Print infix expression
    cout << "Infix Expression: ";
    printInfix(root);
    cout << endl;

    // Print prefix expression
    cout << "Prefix Expression: ";
    printPrefix(root);
    cout << endl;

    // Print postfix expression
    cout << "Postfix Expression: ";
    printPostfix(root);
    cout << endl;

    // Evaluate final answer
    int answer = evaluate(root);

    cout << "Final Answer: " << answer << endl;

    return 0;
}

