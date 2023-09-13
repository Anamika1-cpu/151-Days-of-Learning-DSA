#include <bits/stdc++.h>
using namespace std;

int missing_Number(int nums[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    int totalSum = ((n) * (n + 1)) / 2;
    int ans = totalSum - sum;
    return ans;
}
int main()
{
    int nums[5] = {1, 2, 4, 5};
    cout << "Missing number in the given array is " << missing_Number(nums, 5) << endl;
    return 0;
}