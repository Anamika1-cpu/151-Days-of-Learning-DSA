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

vector<vector<int>> zigzag_Traversal(Node *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    bool LtoRdir = true; // to track the order of traversal
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int width = q.size(); // for creating vector
        vector<int> oneLevel(width);
        for (int i = 0; i < width; i++)
        {
            Node *front = q.front();
            q.pop();
            int index = LtoRdir ? i : width - i - 1;
            oneLevel[index] = front->data;

            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        // Changing the direction of toggle after completion of 1 level
        LtoRdir = !LtoRdir;
        ans.push_back(oneLevel);
    }
    return ans;
}
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
    vector<vector<int>> ans = zigzag_Traversal(root);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
    }

    return 0;
}