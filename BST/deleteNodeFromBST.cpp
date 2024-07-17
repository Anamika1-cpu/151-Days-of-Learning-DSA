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
Node *deleteFromBST(Node *root, int target)
{
    // find the target & delete it
    if (root == NULL)
        return NULL;
    if (root->data == target)
    {
        // this node should be deleted
        // 4 cases are possible
        // case-1
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // case-2
        else if (root->left != NULL && root->right == NULL)
        {
            Node *childSubtree = root->left;
            delete root;
            return childSubtree;
        }
        // case-3
        else if (root->right != NULL && root->left == NULL)
        {
            Node *childSubtree = root->right;
            delete root;
            return childSubtree;
        }
        else
        {
            // case-4
            Node *maxi = maxValue(root->left);
            root->data = maxi->data;
            root->left = deleteFromBST(root->left, maxi->data);
            return root;
        }
    }
    else if (root->data > target)
    {
        // left me chalo
        root->left = deleteFromBST(root->left, target);
    }
    else
    {
        // right me jao
        root->right = deleteFromBST(root->right, target);
    }
};

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
    root->left->right = new Node(9);
    root->right->right = new Node(15);
    root->right->left = new Node(11);
    //     Tree:
    //      10
    //    /   \
    //   8     12
    //  / \   / \
    // 2   9 11   15
    cout << "Before deleteion:" << endl;
    inorder(root);
    cout << endl;
    root = deleteFromBST(root, 9);
    cout << "After deleteion:" << endl;
    inorder(root);
    return 0;
}