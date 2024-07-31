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
/*The approach to find inorder successor here is that
we are using the property of bst that left Subtree
of BST is smaller than root and greater than right.*/

Node *inorderSuccessor(Node *root, Node *x)
{
    Node *succ = 0;
    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->data > x->data)
        {
            succ = curr;
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    return succ;
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
    Node *a = new Node(10);
    Node *ans = inorderSuccessor(root, root->right);
    cout << ans->data << endl;
    return 0;
}