#include <bits/stdc++.h>
using namespace std;
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

// Here, we are using 2 pointer approach for solving this
// problem, what we are doing here is moving all the unique
// elements in front.

int main()
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
    cout << "Number of unique elements in array is " << remove_Duplicates(v) << endl;
    return 0;
}
