#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    deque<int> dq;
    // processing first window
    for (int i = 0; i < k; i++)
    {
        int element = nums[i];
        // Removing elements from queue which are smaller
        while (!dq.empty() && element > nums[dq.back()])
        {
            dq.pop_back();
        }
        // Now inserting the index of element in queue
        dq.push_back(i);
    }
    // Processing remaining window
    // Removal - removing elements which are out of range of window
    // Addition - adding elements for making window
    for (int i = k; i < nums.size(); i++)
    {
        // Storing ans(In front of the queue the largest element of window will be present)
        ans.push_back(nums[dq.front()]);
        // Removal
        // Out of range elements
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }
        // Removing smaller elements
        int element = nums[i];
        while (!dq.empty() && element > nums[dq.back()])
        {
            dq.pop_back();
        }
        // Addition
        dq.push_back(i);
    }
    // storing last window ans
    ans.push_back(nums[dq.front()]);
    return ans;
}
int main()
{
    vector<int> nums;
    int n;
    cout << "Input the size of array" << endl;
    cin >> n;
    cout << "Input the elements of array" << endl;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    // = {1, 3, -1, -3, 5, 3, 6, 7};
    int k;
    cout << "Input the size of window" << endl;
    cin >> k;
    vector<int> ans = maxSlidingWindow(nums, k);
    cout << "Maximum in every window is" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
