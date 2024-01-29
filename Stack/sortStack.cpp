#include <bits/stdc++.h>
using namespace std;

/*Our idea to create function which is inserting
element in sorted stack is that we will pop the
elements of the stack if we find the element which is to
be inserted is less than the stack top element, and if
the element is greater than the stack top element ,
it means we have to insert there the element,
and after that push back the popped elemnts*/
stack<int> insertSorted(stack<int> &st, int ele)
{
    // base case
    if (st.empty() || ele > st.top())
    {
        st.push(ele);
        return st;
    }
    int temp = st.top();
    st.pop();
    insertSorted(st, ele);
    st.push(temp);
    return st;
}

stack<int> sortStack(stack<int> &st)
{
    if (st.empty())
    {
        return st;
    }
    int temp = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, temp);
    // helper function to insert element in sorted order
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
    s.push(2);
    s.push(5);
    s.push(9);
    cout << "Before sorting elements in the stack is" << endl;
    printStack(s);
    cout << "After sorting elements in the  stack is " << endl;
    stack<int> st = sortStack(s);
    printStack(st);
    return 0;
}