#include <bits/stdc++.h>
using namespace std;
string reverseOnlyLetters(string s)
{
    // TWO POINTER APPROACH

    // Here what we are trying to do is that we are taling
    // two pointers left and right and firstly checking that
    //  the left and right pointers are alphabets or not ,
    //  if they are not alphabet than just move ahead 1 position from left
    //  and move back 1 position from right.
    // And if both pointers point the alphabets tthen swap them
    int n = s.size();
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        if (!isalpha(s[l]))
        {
            l++;
        }
        else if (!isalpha(s[r]))
        {
            r--;
        }
        else
        {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }

    return s;
}

int main()
{
    string s;
    cout << "Input the string" << endl;
    cin >> s;
    cout << "String after reversing only the letters " << endl;
    cout << reverseOnlyLetters(s);
    return 0;
}