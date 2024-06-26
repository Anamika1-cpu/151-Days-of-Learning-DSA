#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
int heightOfTree(Node *root)
{
    // Base case
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    int height = max(leftHeight, rightHeight) + 1;
    // adding 1 for adding root's height

    return height;
}

bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    // finding current nodes's ans
    int heightleft = heightOfTree(root->left);
    int heightright = heightOfTree(root->right);

    int difference = abs(heightleft - heightright);
    bool currentNodeAns = (difference <= 1);

    // finding left and right node's
    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);

    // If leftSubtree, rightSubtree and the root node
    //  is balanced then the binary tree is balanaced
    if (currentNodeAns && leftAns && rightAns)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->left->left->left = new Node(7);

    //     Tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    //  /
    // 7

    bool ans = isBalanced(root1);

    string val = ans ? "Balanced" : "Unbalanced";

    cout << "The Given Binary tree is " << val << endl;

    return 0;
}
