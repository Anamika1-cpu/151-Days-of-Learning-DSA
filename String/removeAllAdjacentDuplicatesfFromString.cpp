#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s)
{
    string ans = "";
    int index = 0;

    while (index < s.length())
    {
        if (ans.length() > 0 && ans[ans.length() - 1] == s[index])
        {
            ans.pop_back();
        }
        else
        {
            ans.push_back(s[index]);
        }
        index++;
    }
    return ans;
}

int main()
{
    string s = "";
    cout << "Input the String" << endl;
    cin >> s;
    cout << "After removing Duplicates the string is " << endl;
    cout << removeDuplicates(s) << endl;
    return 0;
}