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

// App-1
void diagonalTraverse(Node *root, int d, map<int, vector<int>> &diagAns)
{
    // base case
    if (!root)
        return;

    // Storing the elements of same line (i.e same d)
    diagAns[d].push_back(root->data);
    // going left
    diagonalTraverse(root->left, d + 1, diagAns);
    // going right
    diagonalTraverse(root->right, d, diagAns);

    return;
}
vector<int> diagonal(Node *root)
{
    // your code here
    map<int, vector<int>> diagP;
    vector<int> ans;
    diagonalTraverse(root, 0, diagP);
    for (auto it : diagP)
    {
        vector<int> v = it.second;
        for (auto it : v)
            ans.push_back(it);
    }
    return ans;
}

// App-2
vector<int> diagonal2(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        while (temp != NULL)
        {
            ans.push_back(temp->data);
            if (temp->left)
            {
                // we will handle this later
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    return ans;
};

int main()
{
    Node *root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(1);
    root->left->left = new Node(2);
    root->left->right = new Node(3);
    root->right->right = new Node(2);
    root->right->left = new Node(3);
    //     Tree:
    //      5
    //    /   \
    //   1     1
    //  / \   / \
    // 2   3 3   2

    vector<int> ans = diagonal2(root);
    for (auto it : ans)
    {
        std::cout << it << " ";
    }

    return 0;
}
