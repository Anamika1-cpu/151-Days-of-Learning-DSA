#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr, int size)
{
    vector<int> ans(size);
    stack<int> st;
    st.push(-1);

    for (int i = size - 1; i >= 0; i--)
    {
        int curr = arr[i];
        // finding answer for current element
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> arr, int size)
{
    vector<int> ans(size);
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < size; i++)
    {
        int curr = arr[i];
        // finding answer for current element
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    vector<int> next = nextSmallerElement(heights, heights.size());
    // next should not contain -1
    for (int i = 0; i < next.size(); i++)
    {
        if (next[i] == -1)
        {
            next[i] = next.size();
        }
    }
    vector<int> prev = prevSmallerElement(heights, heights.size());
    int maxArea = INT_MIN;
    for (int i = 0; i < heights.size(); i++)
    {
        int length = heights[i];
        int width = next[i] - prev[i] - 1;
        int currArea = width * length;
        maxArea = max(maxArea, currArea);
    }
    return maxArea;
}

int main()
{
    int size;
    cout << "Enter the size of array of heights" << endl;
    cin >> size;
    vector<int> heights(size);
    cout << "Enter the elements for array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> heights[i];
    }
    int ans = largestRectangleArea(heights);
    cout << "Maximum Reactangular area is " << endl;
    cout << ans;
    return 0;
}