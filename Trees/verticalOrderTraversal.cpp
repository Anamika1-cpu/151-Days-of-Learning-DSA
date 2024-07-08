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

vector<vector<int>> verticalTraversal(Node *root)
{
    vector<vector<int>> ans;
    // queue for storing nodes with it's horizontal distance
    queue<pair<Node *, pair<int, int>>> q;
    // Pair-------------> HD/row   Level/col
    q.push({root, {0, 0}});
    // Since intially horizontal distance and lvl is 0 for root
    map<int, map<int, multiset<int>>> mp;
    // HD        LVL     node data(here more than 1 item can be
    // present at different level with same hd)
    // eg. -1, {3,{15,2}}

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        mp[hd][lvl].insert(frontNode->data);

        if (frontNode->left)
        {
            q.push({frontNode->left, {hd - 1, lvl + 1}});
        }
        if (frontNode->right)
        {
            q.push({frontNode->right, {hd + 1, lvl + 1}});
        }
    }
    for (auto i : mp)
    {
        auto &levelmap = i.second;
        vector<int> vLine;
        for (auto j : levelmap)
        {
            auto &mset = j.second;
            vLine.insert(vLine.end(), mset.begin(), mset.end());
            // Inserting all the elements from the multiset mset
            //  into the vector vLine.
            //  The insert function appends the elements from mset to the end of vLine.
        }
        ans.push_back(vLine);
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
    vector<vector<int>> ans = verticalTraversal(root);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
    }

    return 0;
}