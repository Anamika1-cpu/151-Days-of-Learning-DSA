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

Node *insertToBST(Node *root, int data)
{
    if (!root)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        // attaching node to the right side of subtree
        root->right = insertToBST(root->right, data);
    }
    else
    {
        // attaching node to the left side of subtree
        root->left = insertToBST(root->left, data);
    }
    return root;
}
void createBST(Node *&root)
{
    cout << "Enter data:" << endl;
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertToBST(root, data);
        cout << "Enter data:" << endl;
        cin >> data;
    }
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // lnr
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
};
int main()
{
    Node *root = NULL;
    createBST(root);
    inorder(root);
    return 0;
}