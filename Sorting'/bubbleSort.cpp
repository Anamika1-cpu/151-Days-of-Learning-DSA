#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}
void bubbleSort(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = 0; j < nums.size() - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

int main()
{
    vector<int> nums = {23, 5, 1, -4, 8, 90};
    bubbleSort(nums);
    print(nums);
    return 0;
}