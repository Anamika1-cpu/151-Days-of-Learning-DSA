#include <bits/stdc++.h>
using namespace std;

int findIndexM1(string haystack, string needle)
{
    return haystack.find(needle);
}

int findIndexM2(string haystack, string needle)
{
    int n = haystack.size();
    int m = needle.size();

    for (int i = 0; i <= n - m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (needle[j] != haystack[i + j])
            {
                break;
            }
            if (j == m - 1)
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    string haystack, needle;
    cout << "Input the strings" << endl;
    cin >> haystack >> needle;
    int ans = findIndexM2(haystack, needle);
    if (ans == -1)
    {
        cout << "Needle string not found in haystack" << endl;
    }
    else
    {
        cout << "The index of the string is" << endl;
        cout << findIndexM2(haystack, needle) << endl;
    }

    return 0;
}