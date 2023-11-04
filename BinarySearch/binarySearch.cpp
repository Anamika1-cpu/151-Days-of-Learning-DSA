#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    int ans = binary_search(nums, target);
    if (ans != -1)
    {
        cout << "Element is present at index " << ans << endl;
    }
    else
    {
        cout << "Element is not present in the array" << endl;
    }
    return 0;
}