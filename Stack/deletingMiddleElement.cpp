#include <bits/stdc++.h>
using namespace std;

void deleteMid_util(stack<int> &s, int sizeOfStack, int current)
{
    // if current pointer is half of the size of stack then we
    // are accessing the middle element of stack.
    if (current == sizeOfStack / 2)
    {
        s.pop();
        return;
    }

    // storing the top element in a variable and popping it.
    int x = s.top();
    s.pop();
    current += 1;

    // calling the function recursively.
    deleteMid_util(s, sizeOfStack, current);

    // pushing the elements (except middle element) back
    // into stack after recursion calls.
    s.push(x);
}
stack<int> deleteMid(stack<int> &s, int sizeOfStack)
{
    deleteMid_util(s, sizeOfStack, 0);
    return s;
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
    stack<int> st;
    st.push(40);
    st.push(30);
    st.push(20);
    st.push(10);

    cout << "Before deleting Middle element of stack " << endl;
    printStack(st);
    stack<int> s = deleteMid(st, st.size());
    cout << "After deleting Middle element of stack " << endl;
    printStack(s);

    return 0;
}