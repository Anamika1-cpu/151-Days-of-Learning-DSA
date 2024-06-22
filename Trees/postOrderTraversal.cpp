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

void postOrder(Node *root)
{
    // base case
    if (root == NULL)
        return;

    // LRN
    // Left node
    postOrder(root->left);
    // Right node
    postOrder(root->right);
    // Node current
    cout << root->data << " ";
}

int main()
{
    // Creating Binary Tree
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    //     Tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    cout << "Postorder traversal of Binary Tree:" << endl;
    postOrder(root1);
    return 0;
}