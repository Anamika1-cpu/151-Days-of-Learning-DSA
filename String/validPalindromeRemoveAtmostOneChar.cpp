#include <bits/stdc++.h>
using namespace std;
bool checkPalindrome(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}
bool validPalindrome(string s)
{
    int j = s.length() - 1;
    int i = 0;
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            // we need to remove a character
            // removing ith character and checking fot the palindrome
            bool ans1 = checkPalindrome(s, i + 1, j);
            // removing jth character and checking fot the palindrome
            bool ans2 = checkPalindrome(s, i, j - 1);

            return ans1 || ans2;
            // returning the string which is making palindrome after
            //  removing a character
        }
    }
    // if we are reaching here, this means that the string is
    // already a valid palindrome
    return true;
}

int main()
{

    string s;
    cout << "Input the string" << endl;
    cin >> s;
    bool ans = validPalindrome(s);
    if (ans == false)
    {
        cout << "The string " << s << " cannot be a valid palindrome " << endl;
    }
    else
    {
        cout << "The string " << s << " can be a valid palindrome" << endl;
    }
    return 0;
}