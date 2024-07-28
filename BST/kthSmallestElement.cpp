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
int kthSmallest(Node *root, int &k)
{
    if (root == NULL)
        return -1;
    // Inorder //LNR
    // L
    int leftAns = kthSmallest(root->left, k);
    if (leftAns != -1)
        return leftAns;
    // N
    k--;
    {
        return root->data;
    }
    // R
    int rightAns = kthSmallest(root->right, k);
    return rightAns;
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

    int k = 3;
    int ans = kthSmallest(root, k);
    cout << ans << endl;
    return 0;
}