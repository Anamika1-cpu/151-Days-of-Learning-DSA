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

int maxValue(Node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}
int minValue(Node *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

bool isBST(Node *root)
{
    if (root == NULL)
        return true;
    // max of left is greater than root
    else if (root->left != NULL && maxValue(root->left) >= root->data)
    {
        return false;
    }
    // min of right is less than root
    else if (root->right != NULL && minValue(root->right) <= root->data)
    {
        return false;
    }
    // if one of the subtree is not bst
    else if (!isBST(root->left) || !isBST(root->right))
    {
        return false;
    }
    else
        return true;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(9);
    root->right->right = new Node(15);
    root->right->left = new Node(11);
    //     Tree:
    //      10
    //    /   \
    //   8     12
    //  / \   / \
    // 2   9 11   15
    bool ans = isBST(root);
    cout << ans;
    return 0;
}