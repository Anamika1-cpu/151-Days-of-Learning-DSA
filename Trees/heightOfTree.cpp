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

int heightOfTree(Node *root)
{
    // Base case
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    int height = max(leftHeight, rightHeight) + 1;
    // adding 1 for adding root's height

    return height;
}

// Method 2
// Using Level Order Trversal
int maxHeight(Node *root)
{
    // Base case
    if (root == NULL)
    {
        return 0;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int count = 1; // Since 1 Null is pushed, means 1 level is pushed

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            if (!q.empty())
            {
                count++;
                q.push(NULL);
            }
        }
        else
        {
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
    }

    return count;
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
    cout << "Height of the given tree is" << endl;
    cout << heightOfTree(root1) << endl;
    cout << maxHeight(root1) << endl;

    return 0;
}