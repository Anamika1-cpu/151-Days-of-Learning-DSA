#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch)
{
    ch = tolower(ch);
    return ch == 'a' || ch == 'o' || ch == 'i' || ch == 'e' || ch == 'u';
}
string reverseVowels(string s)
{
    int l = 0;
    int h = s.size() - 1;
    while (l < h)
    {
        if (isVowel(s[l]) && isVowel(s[h]))
        {
            swap(s[l], s[h]);
            l++;
            h--;
        }
        else if (isVowel(s[l]) == 0)
        {
            l++;
        }
        else
        {
            h--;
        }
    }
    return s;
}

int main()
{
    string s;
    cout << "Input the string " << endl;
    cin >> s;
    string ans = reverseVowels(s);
    cout << "After reversing vowels the string is " << endl;
    cout << ans << endl;
    return 0;
}