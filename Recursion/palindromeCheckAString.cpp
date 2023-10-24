#include <bits/stdc++.h>
using namespace std;

// we are solvig this problem using recursion
// Here, what we are trying to do is taking two pointers
// start and end, while itearating if start and end are
// not equal at some point before itearting the string,
// this means that the string is not palindrome
bool isPalindrome(string &s, int start, int end)
{
    // base case
    if (start > end)
    {
        return true;
    }
    // one condition
    if (s[start] != s[end])
    {
        return false;
    }
    // recursive case
    isPalindrome(s, start + 1, end - 1);
}

int main()
{

    string s;
    cout << "Input the string" << endl;
    cin >> s;
    int start = 0;
    int end = s.length() - 1;
    bool ans = isPalindrome(s, start, end);
    if (ans == true)
    {
        cout << "String is Palindrome" << endl;
    }
    else
    {
        cout << "String is not Palindrome" << endl;
    }
    return 0;
}