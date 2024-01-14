#include <bits/stdc++.h>
using namespace std;

int method1_Sort(vector<int> &v)
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == v[i + 1])
        {
            return v[i];
        }
    }
    return -1;
};
// this method is a brute force method
// In this method we are sorting the array &
// checking that the 2 consecutive elements are same or not
//  T.C = O(n(logn))

int method2_NegMarking(vector<int> &v)
{
    int ans = -1;
    for (int i = 0; i < v.size(); i++)
    {
        int index = abs(v[i]);

        if (v[index] < 0)
        {
            ans = index;
            break;
        }

        v[index] *= -1;
    }
    return ans;
}
// this method is knwon as Negative marking method because
// in this method we are marking the index's value(i.e., v[index])
// as negative to keep a track of that value and chacking if we are
// finding any negative value in iteration, this means that was
// the duplicated element
// T.C = O(n)

int method3_Positioning(vector<int> &v)
{
    while (v[0] != v[v[0]])
    {
        swap(v[0], v[v[0]]);
    }
    return v[0];
}
// this methos is known as Positioning Method, as in this method we
//  are just trying to put the value to its index's place
//  (i.e, if there is a value 3, so it should be at index 3)
// In this way we will get the dulicate element on first index
// T.C - O(n)

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
    cout << "Repeated element in array is " << method3_Positioning(v);
    return 0;
}