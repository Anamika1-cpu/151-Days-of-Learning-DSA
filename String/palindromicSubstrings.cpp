#include <bits/stdc++.h>
using namespace std;

int expand(string s, int i, int j)
{
    int count = 0;
    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        count++;
        // here we are expanding the string
        i--;
        j++;
    }
    return count;
}
int countSubstrings(string s)
{
    int totalCount = 0;
    for (int center = 0; center < s.length(); center++)
    {
        // Counting of odd length palindromic substrings
        int oddLengthSubstrings = expand(s, center, center);
        // Counting of even length palindromic substrings
        int evenLengthSubstrings = expand(s, center, center + 1);

        totalCount += oddLengthSubstrings + evenLengthSubstrings;
    }
    return totalCount;
}

int main()
{
    string s;
    cout << "Enter the string" << endl;
    cin >> s;
    cout << "The number of palindromic substrings is " << endl;
    cout << countSubstrings(s) << endl;
    return 0;
}