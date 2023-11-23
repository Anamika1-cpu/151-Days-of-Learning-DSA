#include <bits/stdc++.h>
using namespace std;

// this function will normalize the pattern as well as
//  the strings, so that we can match them
void create_Mapping(string &str)
{
    char start = 'a';
    char mapping[300] = {0};

    for (auto ch : str)
    {
        if (mapping[ch] == 0)
        {
            mapping[ch] = start;
            start++;
        }
    }
    // update the string
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        str[i] = mapping[ch];
    }
}

vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    vector<string> ans;
    // normalizing the pattern
    create_Mapping(pattern);
    for (auto word : words)
    {
        string temp = word;
        create_Mapping(temp);
        if (temp == pattern)
        {
            ans.push_back(word);
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Input size of the vector of words " << endl;
    cin >> n;
    vector<string> words(n);
    cout << "Input the vector of words " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    string pattern;
    cout << "Input the pattern to check" << endl;
    cin >> pattern;
    cout << "Output the words that match the pattern" << endl;
    vector<string> ans = findAndReplacePattern(words, pattern);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}