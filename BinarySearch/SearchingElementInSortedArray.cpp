#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int target)
{
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
}
int main()
{
    int n = 5;
    int arr[n] = {7, 8, 9, 10, 11};
    int target;
    target = 117;

    cout << binarySearch(arr, n, target) << endl;
    return 0;
}
