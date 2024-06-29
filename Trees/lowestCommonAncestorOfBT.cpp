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

Node *lca(Node *root, Node *p, Node *q)
{
    // Base case
    if (root == NULL)
        return NULL;
    if (root->data == p->data || root->data == q->data)
        return root;
    Node *leftAns = lca(root->left, p, q);
    Node *rightAns = lca(root->right, p, q);

    if (leftAns != NULL && rightAns == NULL)
        return leftAns;
    else if (leftAns == NULL && rightAns != NULL)
        return rightAns;
    return root;
}

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->left->left->left = new Node(7);

    //     Tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    //  /
    // 7

    int p = 4;
    int q = 5;
    cout << "Lowest common ancestor of " << p << " & " << q << " is ";
    Node *ans = lca(root1, root1->left->left, root1->left->right);
    cout << ans->data;
    return 0;
}