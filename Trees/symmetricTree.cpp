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

// bool isMirror(Node *p, Node *q)
// {
//     if (!p && !q)
//         return true;
//     if (p && q)
//     {
//         return (p->data == q->data) &&
//                isMirror(p->left, q->right) &&
//                isMirror(p->right, q->left);
//     }
//     return false;
// }
// bool isSymmetric(Node *root)
// {
//     return isMirror(root->left, root->right);
// }

bool isMirror(Node *p, Node *q)
{
    if (!p && !q)
        return true;
    if (p && q)
    {
        return (p->data == q->data) &&
               isMirror(p->left, q->right) &&
               isMirror(p->right, q->left);
    }
    return false;
}
bool isSymmetric(Node *root)
{
    return isMirror(root->left, root->right);
}
int main()
{
    Node *root1 = new Node(5);
    root1->left = new Node(1);
    root1->right = new Node(1);
    root1->left->left = new Node(2);
    root1->left->left->right = new Node(3);
    root1->left->right = new Node(2);
    //     Tree:
    //      5
    //    /   \
    //   1     1
    //  /       \
    // 2         2
    bool ans = isSymmetric(root1);
    cout << ans;

    // return 0;
}
