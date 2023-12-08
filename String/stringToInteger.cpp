#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    int num = 0;
    int i = 0;
    int sign = 1; // this is for tracking sign,
    // here are we initializing wth 1 which means positive

    while (s[i] == ' ')
    {
        i++;
    }
    // Here we are removing any leading spaces
    if (i < s.size() && s[i] == '-' || s[i] == '+')
    {
        sign = s[i] == '+' ? 1 : -1;
        i++;
    }
    // Here we checking the sign
    while (i < s.size() && isdigit(s[i]))
    {
        if (num > INT_MAX / 10 || num == INT_MAX / 10 && s[i] > '7')
        {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
        // This is the special case where we are checking that
        //  the input which is given is in range i.e.,it should
        //   be range of [-2^31, 2^31 - 1]
        num = num * 10 + (s[i] - '0');
        ++i;
    }
    return sign * num;
}

int main()
{
    string s;
    cout << "Input the string" << endl;
    cin >> s;
    cout << "The integer form of the string is " << endl;
    cout << myAtoi(s) << endl;
    return 0;
}