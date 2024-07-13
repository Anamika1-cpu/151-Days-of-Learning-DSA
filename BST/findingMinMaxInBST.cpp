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
Node *minValue(Node *root)
{
    if (root == NULL)
    {
        cout << "NO MIN VALUE" << endl;
        return NULL;
    }
    Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *maxValue(Node *root)
{
    if (root == NULL)
    {
        cout << "No max value found" << endl;
        return NULL;
    }
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
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
    inorder(root);
    Node *max = maxValue(root);
    Node *min = minValue(root);
    cout << "Max value: " << max->data << endl;
    cout << "Min value: " << min->data << endl;
    return 0;
}