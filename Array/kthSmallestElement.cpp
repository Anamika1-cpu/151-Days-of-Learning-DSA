#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int arr[8] = {0, 8, 6, 4, 5, 2, 9, 7};
    sort(arr, arr + 8);
    cout << arr[k - 1];
    return 0;
}