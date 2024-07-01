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

Node *solve(Node *root, int node, int &k)
{
    if (root == NULL)
        return NULL;
    if (root->data == node)
    {
        return root;
    }
    Node *leftAns = solve(root->left, node, k);
    Node *rightAns = solve(root->right, node, k);

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, node, k);
    if (ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    //     Tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    int k = 2;
    int n = 5;
    int ans = kthAncestor(root1, k, n);
    cout << "Kth ancestor of " << n << " is " << ans << endl;
    return 0;
}