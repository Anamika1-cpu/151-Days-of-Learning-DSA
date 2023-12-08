#include <bits/stdc++.h>
using namespace std;

// This is the function to check the string
// is palindromic or not
bool isPalindromic(string &s, int start, int end)
{
    while (start < end)
    {
        if (s[start] == s[end])
        {
            start++;
            end--;
        }
        else
        {

            return false;
        }
    }
    return true;
}

string longestPalindromic(string s)
{
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            // from these for loops we are finding all the substrings
            if (isPalindromic(s, i, j))
            // here we are checking for the palindromic
            {
                string longSubstring = s.substr(i, j - i + 1);
                // here we are checking the size of string to find the longest one
                result = longSubstring.size() > result.size() ? longSubstring : result;
            }
        }
    }
    return result;
}
int main()
{
    string s;
    cout << "Input the string" << endl;
    cin >> s;
    string ans = longestPalindromic(s);
    cout << "The longest substring from all the substrings is " << endl;
    cout << ans << endl;
    return 0;
}