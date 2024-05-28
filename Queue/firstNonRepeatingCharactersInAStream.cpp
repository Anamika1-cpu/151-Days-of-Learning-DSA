// i/p -> ababc
// streams - a, ab, aba, abab, ababc
// o/p -> aab#c

#include <bits/stdc++.h>
using namespace std;

void firstNonRepeating(string &s)
{
    // 1.Keep track of every character's frequency
    queue<char> q;
    int freq[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        freq[ch - 'a']++;
        q.push(ch);
        // 2.Find Answer
        while (!q.empty())
        {
            char frontChar = q.front();
            if (freq[frontChar - 'a'] > 1)
            {
                // this means that the character is repeating
                q.pop();
            }
            else
            {
                // means when the frequency of character is 1
                cout << frontChar << " ";
                break;
            }
        }
        if (q.empty())
        {
            // every character is repeating
            cout << "#"
                 << " ";
        }
    }
}
int main()
{
    string s;
    cout << "Input the string " << endl;
    cin >> s;
    cout << "The non repeating character is stream is" << endl;
    firstNonRepeating(s);
    return 0;
}