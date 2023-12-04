#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    char hash[256] = {0};
    bool isTCharMapped[256] = {false};

    for (int i = 0; i < s.length(); i++)
    {
        if (hash[s[i]] == 0 && isTCharMapped[t[i]] == 0)
        {
            hash[s[i]] = t[i];
            isTCharMapped[t[i]] = true;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (char(hash[s[i]]) != t[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s, t;
    cout << "Input the first string " << endl;
    cin >> s;
    cout << "Input the second string " << endl;
    cin >> t;
    bool ans = isIsomorphic(s, t);
    if (ans == true)
    {
        cout << "Strings are isomprphic" << endl;
    }
    else
    {
        cout << "Strings are not isomprphic" << endl;
    }
    return 0;
}