#include <bits/stdc++.h>
using namespace std;

vector<int> two_pointer_method(vector<int> &nums, int k, int x)
{
    int l = 0;
    int h = nums.size() - 1;
    while (h - l >= k)
    {
        // calculating difference
        if (x - nums[l] > nums[h] - x)
        {
            l++;
        }
        else
        {
            h--;
        }
    }
    return vector<int>(nums.begin() + l, nums.begin() + h + 1);
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 4;
    int x = -1;
    vector<int> ans = two_pointer_method(a, 4, 3);
    cout << "The closest elements to " << x << " are:" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}