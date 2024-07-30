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
// Approach: We will store the bst in array using inorder
// traversal, So that the elemenst of array are sorted
//  and then we will use 2 ptr approach to find the pair

void storeInorder(Node *root, vector<int> &inorder)
{
    // Base case
    if (root == NULL)
        return;
    // LNR - Inorder
    // L
    storeInorder(root->left, inorder);
    // N
    inorder.push_back(root->data);
    // R
    storeInorder(root->right, inorder);
}
bool findTarget(Node *root, int k)
{
    vector<int> inorder;
    storeInorder(root, inorder);
    // find the target using 2 Pointer approach
    int start = 0, end = inorder.size() - 1;
    while (start < end)
    {
        int sum = inorder[start] + inorder[end];
        if (sum == k)
            return true;
        if (sum < k)
            start++;
        else
            end--;
    }
    return false;
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
    int k = 30;
    cout << findTarget(root, k);

    return 0;
}