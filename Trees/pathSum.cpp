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

bool solve(Node *root, int sum, int targetSum)
{
    // checking for 1 node
    if (root == NULL)
        return false;
    // Adding every node's value till leaf node comes
    sum += root->data;
    // Conditon for leaf node
    if (root->left == NULL && root->right == NULL)
    {
        if (sum == targetSum)
            return true;
        else
            return false;
    }
    // Rest will do the recusrion
    bool leftAns = solve(root->left, sum, targetSum);
    bool rightAns = solve(root->right, sum, targetSum);

    return leftAns || rightAns;
}
bool hasPathSum(Node *root, int targetSum)
{
    int sum = 0;
    bool ans = solve(root, sum, targetSum);
    return ans;
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

    int targetSum = 9;
    bool ans = hasPathSum(root1, targetSum);
    cout << ans << endl;
    return 0;
}