#include <bits/stdc++.h>
using namespace std;

stack<int> insertAtBottom(stack<int> &st, int data)
{
    // base case
    if (st.size() == 0)
    {
        st.push(data);
        return st;
    }
    // solving 1 case
    int temp = st.top();
    st.pop();

    // solving remaining cases through recursion
    insertAtBottom(st, data);

    // backtrack
    st.push(temp);
    return st;
}
stack<int> Reverse(stack<int> &st)
{
    if (st.size() == 0)
    {
        return st;
    }
    int temp = st.top();
    st.pop();
    Reverse(st);
    return insertAtBottom(st, temp);
}
void printStack(stack<int> &st)
{
    stack<int> temp = st;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl
         << endl;
}
int main()
{
    stack<int> s;
    s.push(30);
    s.push(40);
    s.push(10);
    cout << "Before reversing the stack is" << endl;
    printStack(s);
    cout << "After reversing the stack is " << endl;
    stack<int> st = Reverse(s);
    printStack(st);
    return 0;
}