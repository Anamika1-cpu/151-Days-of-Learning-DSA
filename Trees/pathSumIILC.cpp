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

void solve(Node *root, int targetSum, vector<vector<int>> &ans, vector<int> temp, int sum)
{
    // Base Case
    if (root == NULL)
        return;
    sum += root->data;
    temp.push_back(root->data);

    // Extra case(leaf node)
    if (root->left == NULL && root->right == NULL)
    {
        // checking if the current path having target sum or not
        if (targetSum == sum)
        {
            ans.push_back(temp);
        }
        else
        {
            return;
        }
    }
    // We have handled 1 case, now rest will handle recursion
    solve(root->left, targetSum, ans, temp, sum);
    solve(root->right, targetSum, ans, temp, sum);
}
vector<vector<int>> PathSum(Node *root, int targetSum)
{
    vector<vector<int>> ans;
    vector<int> tmp;
    int sum = 0;
    solve(root, targetSum, ans, tmp, sum);
    return ans;
}

int main()
{
    Node *root1 = new Node(2);
    root1->left = new Node(4);
    root1->right = new Node(16);
    root1->right->right = new Node(1);
    root1->right->right->right = new Node(2);
    root1->right->right->right->right = new Node(3);
    root1->right->left = new Node(3);
    root1->right->left->right = new Node(3);
    root1->left->left = new Node(8);
    root1->left->left->left = new Node(10);
    root1->left->right = new Node(6);
    root1->left->right->left = new Node(8);
    root1->left->right->left->left = new Node(12);

    /*
          2
        /   \
       4     16
     /  \    / \
    8    6  3    1
   /    /   \     \
 10    8     3     2
       /           \
      12            3

     */
    
    int targetSum = 24;
    vector<vector<int>> ans = PathSum(root1, targetSum);
    cout << "Paths having the target Sum" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}