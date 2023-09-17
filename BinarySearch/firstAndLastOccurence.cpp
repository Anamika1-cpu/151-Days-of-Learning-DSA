#include <bits/stdc++.h>
using namespace std;

int firstOcc(int arr[], int n, int target)
{
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (arr[mid] == target)
        {
            ans = mid;
            end = mid - 1;
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
    return ans;
}

int lastOcc(int arr[], int n, int target)
{
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (arr[mid] == target)
        {
            ans = mid;
            start = mid + 1;
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
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of elements of array" << endl;
    cin >> n;

    int arr[n];

    cout << "Enter the elements of array" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target" << endl;
    cin >> target;

    cout << "First occurence of " << target << " is at index " << firstOcc(arr, 7, target) << endl;

    cout << "Last occurence of " << target << " is at index " << lastOcc(arr, 7, target);

    return 0;
}