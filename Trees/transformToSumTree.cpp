#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int sum(Node *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
    {
        // leaf node
        int temp = root->data;
        root->data = 0;
        return temp;
    }
    int lSum = sum(root->left);
    int rSum = sum(root->right);
    int temp = root->data;
    root->data = lSum + rSum;
    return root->data + temp;
};
void toSumTree(Node *node)
{
    sum(node);
}
void inorder(Node *root)
{
    // base
    if (root == NULL)
    {
        return;
    }

    // L -> left node data
    inorder(root->left);

    // N->current node data
    cout << root->data << " ";

    // R -> right node data
    inorder(root->right);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->right = new Node(5);
    root->right->left = new Node(7);
    //     Tree:
    //      10
    //    /   \
    //  -2     6
    //  / \   / \
    // 8   -4 7   5
    toSumTree(root);
    inorder(root);
    return 0;
}