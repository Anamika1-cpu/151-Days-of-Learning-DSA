#include <bits/stdc++.h>
using namespace std;
int main()

    int remove_Duplicates(vector<int> &arr)
{
    int i = 1;
    int j = 0;

    while (i < arr.size())
    {
        if (arr[i] == arr[j])
        {
            i++;
        }
        else
        {
            j++;
            arr[j] = arr[i];
            i++;
        }
    }
    return j + 1;
}
{
    int n;
    cout << "Enter the number of elements in array" << endl;
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements of array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "Number of unnique elements in array is" << remove_Duplicates(v) << endl;
    return 0;
}