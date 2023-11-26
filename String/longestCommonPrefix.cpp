#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans = "";
    int i = 0;
    while (true)
    {
        char curr_ch = 0;
        for (string str : strs)
        {
            // out of bound check
            if (i >= str.size())
            {
                curr_ch = 0;
                break;
            }
            // getting the new character
            if (curr_ch == 0)
            {
                curr_ch = str[i];
            }
            // if character doesnot match
            else if (curr_ch != str[i])
            {
                curr_ch = 0;
                break;
            }
        }
        if (curr_ch == 0)
        {
            break;
        }
        ans.push_back(curr_ch);
        i++;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of strings vector" << endl;
    cin >>
        n;
    vector<string> strs(n);
    cout << "Enter the strings " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }
    cout << "The longest common prefix is " << endl;
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}