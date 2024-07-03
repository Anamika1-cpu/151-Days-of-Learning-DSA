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

bool isIdentical(Node *p, Node *q)
{
    // Base case
    if (p == NULL && q == NULL)
    {
        return true;
    }
    else if (p && q)
    {
        return (p->data == q->data) &&
               isIdentical(p->left, q->left) &&
               isIdentical(p->right, q->right);
    }
    // This means one is NULL and the other one is not NULL
    else
    {
        return false;
    }
}

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    Node *root2 = new Node(1);
    root2->left = new Node(6);
    root2->right = new Node(3);
    //     Tree1:      Tree1:
    //       1          1
    //      / \        / \
    //     2   3      2   3
    bool ans = isIdentical(root1, root2);
    if (ans == true)
        cout << "Trees are identical" << endl;
    else
        cout << "Trees are not identical" << endl;
    return 0;
}