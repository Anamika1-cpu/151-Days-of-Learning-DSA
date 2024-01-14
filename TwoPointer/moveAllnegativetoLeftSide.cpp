#include <bits/stdc++.h>
using namespace std;

void moveToNegative(int a[], int n)
{
    int l = 0;
    int h = n - 1;
    while (l < h)
    {
        // if negative number is already in left
        if (a[l] < 0)
        {
            l++;
        }
        // if positive number is already in left
        else if (a[h] > 0)
        {
            h--;
        }
        else
        {
            swap(a[l], a[h]);
            l++;
            h--;
        }
    }
}

int main()
{
    int arr[5] = {1, -3, 2, -6, 5};
    moveToNegative(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}