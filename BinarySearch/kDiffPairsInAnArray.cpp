#include <bits/stdc++.h>
using namespace std;

// this is the brute force method for finding the
// distinct pairs, In this method we are looping
// throught the vector and checking all the pairs that can be created
// T.C - O(n^2)
set<pair<int, int>> method1_BruteForce(vector<int> &nums, int k)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(nums[i] - nums[j]) == k)
            {
                ans.insert({nums[i], nums[j]});
            }
        }
    }
    return ans;
}

// This is the better approach than nrute force,
// here we are sorting the array and then taking
// two pointers to find the pair
int method2_TwoPointer(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int i = 0;
    int j = 1;
    set<pair<int, int>> ans;
    while (j < nums.size())
    {
        int diff = nums[j] - nums[i];
        if (diff == k)
        {
            ans.insert({nums[i], nums[j]});
            i++;
            j++;
        }
        else if (diff > k)
        {
            i++;
        }
        else
        {
            j++;
        }
        if (i == j)
        {
            j++;
            // this condition is for the special case
            //  where it is taking i==j
        }
    }
    return ans.size();
}
// function for binary search
int binarySearch(vector<int> &nums, int s, int x)
{
    int e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (nums[mid] == x)
        {
            return mid;
        }
        else if (nums[mid] < x)
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

// In this method we are using the concept that nums[j]-nums[i] = k,
// i.e, nums[j] = k + nums[i], If we found the number k + nums[i]
// in the vector, it means we found a pair. Here we are searching
// the element using binary search
int method3_BinarySearch(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if ((binarySearch(nums, i + 1, nums[i] + k)) != -1)
        {
            ans.insert({nums[i], nums[i] + k});
        }
    }
    return ans.size();
}
int main()
{
    vector<int> nums = {1, 4, 3, 1, 5};
    int k = 2;
    set<pair<int, int>> a = method1_BruteForce(nums, k);
    cout << "The pairs are: " << endl;
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    // cout << method2_TwoPointer(nums, k) << endl;
    cout << "The count of distinct pairs is " << method3_BinarySearch(nums, k) << endl;
    return 0;
}