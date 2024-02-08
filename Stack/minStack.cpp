#include <bits/stdc++.h>
using namespace std;

/*Here, Our idea to create a minStack is by using
pair we will create a vector containing pair of
the value and the minimum value */

class MinStack
{
public:
    vector<pair<int, int>> st;
    void push(int val)
    {
        if (st.empty())
        {
            // Inserting the first element
            pair<int, int> p;
            p.first = val;
            p.second = val;
            st.push_back(p);
        }
        else
        {
            pair<int, int> p;
            p.first = val;
            int oldMin = st.back().second;
            p.second = min(val, oldMin);
            st.push_back(p);
        }
    }
    int pop()
    {
        if (!st.empty())
        {
            st.pop_back();
        }
    }

    int top()
    {
        if (!st.empty())
        {
            pair<int, int> rightMostElement = st.back();
            return rightMostElement.first;
        }
    }

    int getMin()
    {
        if (!st.empty())
        {
            pair<int, int> rightMostElement = st.back();
            return rightMostElement.second;
        }
    }
};

int main()
{
    MinStack m;
    m.push(1);
    m.push(4);
    cout << m.getMin() << endl;
    m.push(5);
    m.pop();
    m.push(9);
    cout << m.top() << endl;
    cout << m.getMin() << endl;
    return 0;
}