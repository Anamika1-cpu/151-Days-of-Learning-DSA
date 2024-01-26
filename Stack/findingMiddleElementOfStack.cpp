#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &st, int &pos, int &ans)
{
    // base case
    if (pos == 1)
    {
        ans = st.top();
        return;
    }
    pos--;
    int temp = st.top();
    st.pop();

    // recursive call
    solve(st, pos, ans);
    // backtrack(pushing back the elements which we
    // have popped to reach the middle of the stack)
    st.push(temp);
}

int getMiddleElement(stack<int> &st)
{
    int size = st.size();
    if (st.empty())
        return -1;
    else
    {
        int pos = 0;
        // if size of stack is odd
        if (size % 2 != 0)
        {
            pos = size / 2 + 1;
        }
        else
        {
            // even
            pos = size / 2;
        }
        int ans = -1;
        solve(st, pos, ans);
        return ans;
    }
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    int mid = getMiddleElement(st);
    cout << "Middle element of stack is " << mid << endl;

    return 0;
}