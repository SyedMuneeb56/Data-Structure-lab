#include <iostream>
using namespace std;


class ExprNode
{
public:
    string data;
    ExprNode* left;
    ExprNode* right;

    
    ExprNode(string value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function for inorder traversal with brackets
void printInfix(ExprNode* root)
{
    // Check if node is empty
    if (root == NULL)
    {
        return;
    }

    // Print opening bracket
    if (root->left != NULL)
    {
        cout << "(";
    }

    // Visit left child
    printInfix(root->left);

    // Print current node
    cout << root->data;

    // Visit right child
    printInfix(root->right);

    // Print closing bracket
    if (root->right != NULL)
    {
        cout << ")";
    }
}

// Function for preorder traversal
void printPrefix(ExprNode* root)
{
    if (root == NULL)
    {
        return;
    }

    // Print root first
    cout << root->data << " ";

    // Visit left child
    printPrefix(root->left);

    // Visit right child
    printPrefix(root->right);
}

// Function for postorder traversal
void printPostfix(ExprNode* root)
{
    if (root == NULL)
    {
        return;
    }

    // Visit left child
    printPostfix(root->left);

    // Visit right child
    printPostfix(root->right);

    // Print root node
    cout << root->data << " ";
}

// Function to evaluate expression tree
int evaluate(ExprNode* root)
{
    // If leaf node then return digit
    if (root->left == NULL && root->right == NULL)
    {
        return root->data[0] - '0';
    }

    // Evaluate left and right subtree
    int leftValue = evaluate(root->left);
    int rightValue = evaluate(root->right);

    // Perform operations
    if (root->data == "+")
    {
        cout << leftValue << " + " << rightValue
            << " = " << leftValue + rightValue << endl;

        return leftValue + rightValue;
    }

    else if (root->data == "-")
    {
        cout << leftValue << " - " << rightValue
            << " = " << leftValue - rightValue << endl;

        return leftValue - rightValue;
    }

    else if (root->data == "*")
    {
        cout << leftValue << " * " << rightValue
            << " = " << leftValue * rightValue << endl;

        return leftValue * rightValue;
    }

    return 0;
}

int main()
{
    // Creating operand nodes
    ExprNode* n1 = new ExprNode("3");
    ExprNode* n2 = new ExprNode("5");
    ExprNode* n3 = new ExprNode("8");
    ExprNode* n4 = new ExprNode("2");

    // Creating operator nodes
    ExprNode* plusNode = new ExprNode("+");
    ExprNode* minusNode = new ExprNode("-");
    ExprNode* multiplyNode = new ExprNode("*");

    // Linking nodes according to expression tree

    // (3 + 5)
    plusNode->left = n1;
    plusNode->right = n2;

    // (8 - 2)
    minusNode->left = n3;
    minusNode->right = n4;

    // ((3 + 5) * (8 - 2))
    multiplyNode->left = plusNode;
    multiplyNode->right = minusNode;

    // Print infix expression
    cout << "Infix Expression: ";
    printInfix(multiplyNode);
    cout << endl;

    // Print prefix expression
    cout << "Prefix Expression: ";
    printPrefix(multiplyNode);
    cout << endl;

    // Print postfix expression
    cout << "Postfix Expression: ";
    printPostfix(multiplyNode);
    cout << endl;

    // Evaluate expression tree
    cout << endl;
    cout << "Evaluation:" << endl;

    int answer = evaluate(multiplyNode);

    cout << "Final Answer: " << answer << endl;

    return 0;
}


/* Lab Questions
1. In an expression tree, where are operators usually stored?

Operators are usually stored in internal nodes.

2. Which traversal gives prefix expression?

Preorder traversal gives prefix expression.

3. Which traversal gives postfix expression?

Postorder traversal gives postfix expression.

4. Why should brackets be added in inorder expression output?

Brackets are added to show the correct order of operations.

5. What is the final answer of the given expression tree?

The final answer is 48.*/