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

Node *createTree()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    // step-1 Create Node
    Node *root = new Node(data);

    // step-2 Create left subtree
    root->left = createTree();
    // step-2 Create right subtree
    root->right = createTree();

    return root;
}

// Preorder
//  NLR

void preorder(Node *root)
{
    // base
    if (root == NULL)
    {
        return;
    }
    // N->current node data
    cout << root->data << " ";

    // L -> left node data
    preorder(root->left);

    // R -> right node data
    preorder(root->right);
}

int main()
{
    cout << "Enter values for node" << endl;
    Node *root = createTree();
    preorder(root);
    return 0;
}