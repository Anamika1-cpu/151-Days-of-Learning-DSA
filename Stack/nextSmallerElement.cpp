#include <bits/stdc++.h>
using namespace std;

/* My idea to find the next smaller element for each element given
in array is that i will start traversing the array from right
side and by using stack we will keep track of smaller element*/
vector<int> nextSmallerElement(int *arr, vector<int> &ans, int size)
{
    stack<int> st;
    st.push(-1);

    for (int i = size - 1; i >= 0; i--)
    {
        int curr = arr[i];
        // finding answer for current element
        while (st.top() >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}

int main()
{
    int size;
    cout << "Enter size of array" << endl;
    cin >> size;
    int arr[size];
    cout << "Enter values of array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    vector<int> demo(size);
    vector<int> ans = nextSmallerElement(arr, demo, size);
    cout << "Next smaller elements for each elements are" << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}