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
int diameterOfTree(Node *root)
{
    // base case
    if (root == NULL)
        return 0;
    int op1 = diameterOfTree(root->left);  // for left skewed
    int op2 = diameterOfTree(root->right); // for left skewed
    int op3 = heightOfTree(root->left) + heightOfTree(root->right);

    int diameter = max(op1, max(op2, op3));
    return diameter;
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

    cout << "Diameter of the given tree is" << endl;
    cout << diameterOfTree(root1) << endl;

    return 0;
}
