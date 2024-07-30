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

void convertBSTtoDLL(Node *root, Node *&head)
{
    if (root == NULL)
    {
        return;
    }
    // RNL

    // R
    convertBSTtoDLL(root->right, head);

    // N
    root->right = head;
    if (head != NULL)
        head->left = root;
    head = root;

    // L
    convertBSTtoDLL(root->left, head);
}
void printDLL(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << "<-> ";
        current = current->right;
    }
    cout << endl;
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
    Node *head = NULL;
    convertBSTtoDLL(root, head);
    printDLL(head);
    return 0;
}