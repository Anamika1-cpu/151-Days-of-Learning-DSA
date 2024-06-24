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

vector<int> levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    vector<int> ans;
    while (q.size() > 1)
    {
        Node *frontval = q.front();
        q.pop();
        if (frontval == NULL)
        {
            ans.push_back(-1);
            q.push(NULL);
        }
        else
        {
            // valid
            ans.push_back(frontval->data);
            if (frontval->left != NULL)
                q.push(frontval->left);
            if (frontval->right != NULL)
                q.push(frontval->right);
        }
    }
    return ans;
}

int main()
{
    // Creating Binary Tree
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
    cout << "LevelOrder traversal of Binary Tree:" << endl;
    vector<int> ans = levelOrder(root1);
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == -1)
        {
            cout << endl;
        }
        else
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}