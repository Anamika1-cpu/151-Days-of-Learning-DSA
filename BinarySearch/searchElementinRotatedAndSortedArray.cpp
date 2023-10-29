#include <bits/stdc++.h>
using namespace std;

int findPivotIndex(vector<int> &arr)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (s == e)
        {
            // single element left
            return s;
        }
        if (mid - 1 >= 0 && arr[mid] < arr[mid - 1])
        {
            return mid - 1;
        }
        else if (mid + 1 < n && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[s] > arr[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int binarySearch(vector<int> &arr, int s, int e, int target)
{
    int n = arr.size();
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
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

int search(vector<int> &nums, int target)
{
    int pivotIndex = findPivotIndex(nums);
    int ans = -1;
    // search in A
    if (target >= nums[0] && target <= nums[pivotIndex])
    {
        ans = binarySearch(nums, 0, pivotIndex, target);
    }
    // search in B
    else
    {
        ans = binarySearch(nums, pivotIndex + 1, nums.size() - 1, target);
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter number of elements of array" << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cout << "Enter the number to search" << endl;
    cin >> target;
    cout << "The element is present at index in " << search(nums, target) << endl;
    return 0;
}
