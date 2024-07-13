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
bool searchInBST(Node *root, int target)
{
    // Base case
    if (root == NULL)
        return false;
    // 1 case solved
    if (root->data == target)
    {
        return true;
    }
    // rest will handle by recursion
    bool leftAns = false;
    bool rightAns = false;

    if (target > root->data)
    {
        rightAns = searchInBST(root->right, target);
    }
    else
    {
        leftAns = searchInBST(root->left, target);
    }
    return leftAns || rightAns;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(15);
    root->right->left = new Node(11);
    //     Tree:
    //      10
    //    /   \
    //   8     12
    //  / \   / \
    // 2   4 11   15
    int target = 30;
    cout << searchInBST(root, target);
    return 0;
}