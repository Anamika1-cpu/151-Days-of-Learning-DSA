#include <bits/stdc++.h>
using namespace std;

class SpecialStack
{
    stack<int> s;
    int mini;

public:
    void push(int data)
    {
        if (s.empty())
        {
            s.push(data);

            mini = data;
        }
        else
        {
            if (data < mini)
            {
                s.push(2 * data - mini);

                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }
    void pop()
    {
        if (s.empty())
        {
            return;
        }
        if (s.top() > mini)
        {
            s.pop();
        }
        else
        {
            mini = 2 * mini - s.top();
            s.pop();
        }
    }
    int top()
    {
        if (s.empty())
        {
            return -1;
        }
        int curr = s.top();
        if (curr > mini)
        {
            return curr;
        }
        else
        {
            return mini;
        }
    }
    void printStack()
    {
        while (s.empty())
        {
            stack<int> temp = s;
            cout << "Stack Elements: ";
            while (!temp.empty())
            {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << endl;
        }
    }
    int getMin()
    {
        return mini;
    }
};

int main()
{
    SpecialStack st;

    // Push elements onto the stack
    st.push(5);
    st.push(3);
    st.push(8);
    st.push(2);
    st.push(7);
    // Get the minimum element from the stack
    int minElement = st.getMin();
    cout << "Minimum element in the stack: " << minElement << endl;

    return 0;
}