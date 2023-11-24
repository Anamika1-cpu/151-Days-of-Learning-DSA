#include <bits/stdc++.h>
using namespace std;

bool isValidAnagram_Brute(string s, string t)
{
    // method 1(BruteForce)
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}
bool isValidAnagram_frequency(string s, string t)
{
    // method 2(Frequency)
    int frequency[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        frequency[s[i]]++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        frequency[t[i]]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (frequency[i] != 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string s, t;
    cout << "Input the strings" << endl;
    cin >> s >> t;
    bool ans1 = isValidAnagram_Brute(s, t);
    bool ans2 = isValidAnagram_frequency(s, t);
    if (ans2 == true)
    {
        cout << s << " is an anagram of " << t << endl;
    }
    else
    {
        cout << s << " is not an anagram of " << t << endl;
    }
    return 0;
}