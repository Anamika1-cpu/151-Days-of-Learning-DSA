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

Node *lca(Node *root, Node *p, Node *q)
{
    // Base case:
    if (root == NULL)
        return NULL;
    // case 1: if p and q both comes in left subtree
    // hum recursively p and q tk pohoch jayenge
    if (p->data < root->data && q->data < root->data)
    {
        Node *leftAns = lca(root->left, p, q);
        return leftAns;
    }
    // case 2: if p and q both comes in right subtree
    else if (p->data > root->data && q->data > root->data)
    {
        Node *rightAns = lca(root->right, p, q);
        return rightAns;
    }
    // case 3: if p is in Left subtree and q is in right subtree
    else if (p->data < root->data && q->data > root->data)
    {
        return root;
    }
    // case 4: if q is in Left subtree and p is in right subtree
    else if (q->data < root->data && p->data > root->data)
    {
        return root;
    }
    return root;
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
    Node *p = root->right;
    Node *q = root->right->right;
    Node *ans = lca(root, p, q);
    cout << ans->data;
    return 0;
}