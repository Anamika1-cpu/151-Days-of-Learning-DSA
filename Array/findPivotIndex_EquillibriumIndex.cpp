#include <bits/stdc++.h>
using namespace std;

int pivot_index_method1(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int left_Sum = 0;
        int right_Sum = 0;
        for (int j = 0; j < i; j++)
        {
            left_Sum += arr[j];
        }
        for (int j = i + 1; j < n; j++)
        {
            right_Sum += arr[j];
        }
        if (left_Sum == right_Sum)
        {
            return i;
        }
    }
    return -1;
}
// In this method, the time complexity is O(n^2)
// because there are two loops(one within the other)

int pivot_index_method2(vector<int> &arr)
{
    int n = arr.size();
    vector<int> left_Sum(n, 0);
    vector<int> right_Sum(n, 0);

    for (int i = 1; i < n; i++)
    {
        left_Sum[i] = left_Sum[i - 1] + arr[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        right_Sum[i] = right_Sum[i + 1] + arr[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        if (left_Sum[i] == right_Sum[i])
        {
            return i;
        }
    }
    return -1;
}

// In the second method, We are using vector to store the left sum and right sum
// and here I have not used nested loops but i have used 3 loops separately,
// so the time complexity is O(n) + O(n) + O(n) = O(3n). This method is known as
// PREFIX-SUM

int main()
{
    vector<int> arr;
    cout << "Pivot index/Equillibrium index is present at " << pivot_index_method2(arr) << endl;

    return 0;
}