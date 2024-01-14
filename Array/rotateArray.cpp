#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 7;
    int arr[n] = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    cout << "Original array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = arr[i];
    }
    cout << "Array after rotation by " << k << "elements :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
    return 0;
}