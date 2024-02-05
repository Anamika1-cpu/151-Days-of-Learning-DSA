#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        // for open brackets
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            // for closing brackets
            if (!st.empty())
            {
                // if stack is not empty
                if (ch == ')' && st.top() == '(')
                {
                    st.pop();
                }
                else if (ch == '}' && st.top() == '{')
                {
                    st.pop();
                }
                else if (ch == ']' && st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            // when stack is empty
            else
            {
                return false;
            }
        }
    }
    if (st.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s;
    cout
        << "Enter the string " << endl;
    cin >> s;
    cout << endl;
    bool ans = isValid(s);
    if (ans)
    {
        cout << "The given string is having valid pair of paremtheses" << endl;
        cout << endl;
    }
    else
    {
        cout << "The given string is having Invalid pair of paremtheses" << endl;
        cout << endl;
    }
    return 0;
}