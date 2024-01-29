#include <bits/stdc++.h>
using namespace std;

/*Our idea to solve this problem is that we will pop the
elements of the stack if we find the element which is to
be inserted is less than the stack top element, and if
the element is grater than the stack top element ,
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
    s.push(20);
    s.push(30);
    cout << "Before inserting element in the stack is" << endl;
    printStack(s);
    cout << "After inserting element in the  stack is " << endl;
    int ele = 23;
    stack<int> st = insertSorted(s, ele);
    printStack(st);
    return 0;
}