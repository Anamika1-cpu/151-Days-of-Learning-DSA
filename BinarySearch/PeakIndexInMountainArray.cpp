#include <bits/stdc++.h>
using namespace std;

int PeakIndexInMountainArray(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return e;
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
    int peak = PeakIndexInMountainArray(arr, n);
    cout << "Peak Index in this array is " << peak << endl;
    cout << "Peak Element is " << arr[peak] << endl;

    return 0;
}