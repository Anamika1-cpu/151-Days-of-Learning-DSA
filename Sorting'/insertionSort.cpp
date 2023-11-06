#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

int main()
{
    vector<int> v = {12, 45, 1, 89, 0, 3};
    insertionSort(v);
    cout << "After insertion the vector will be " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}