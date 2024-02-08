#include <bits/stdc++.h>
using namespace std;

bool checkRedundancy(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '*' || ch == '+' || ch == '-' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            int operatorCount = 0;
            while (!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                if (temp == '*' || temp == '/' || temp == '+' || temp == '-')
                {
                    operatorCount++;
                }
                st.pop();
            }
            // We will reach here when opening bracket is present on top
            //  of stack, we will pop that bracket also
            st.pop();
            if (operatorCount == 0)
            {
                return true;
            }
        }
    }
    // If we will reach here this means between every bracket there
    //  is atleast one operator is present
    return false;
}

int main()
{
    string s;
    cout << "Input the string " << endl;
    cin >> s;
    bool ans = checkRedundancy(s);
    if (ans == false)
    {
        cout << "Redundant brackets are not present" << endl;
    }
    else
    {
        cout << "Redundant brackets are present" << endl;
    }
    return 0;
}