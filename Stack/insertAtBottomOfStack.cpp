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
    s.push(10);
    s.push(46);
    s.push(52);
    cout << "Before inserting the element stack is" << endl;
    printStack(s);
    int data = 0;
    stack<int> st = insertAtBottom(s, data);
    cout << "After inserting the element " << data << " stack is " << endl;
    printStack(st);
    return 0;
}