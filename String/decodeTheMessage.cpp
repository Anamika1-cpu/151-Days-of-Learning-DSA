#include <bits/stdc++.h>
using namespace std;

string decodeMessage(string key, string message)
{
    // create mapping
    char start = 'a';
    char mapping[300] = {0};
    for (int i = 0; i < key.length(); i++)
    {
        if (key[i] != ' ' && mapping[key[i]] == 0)
        {
            mapping[key[i]] = start;
            start++;
        }
    }

    // use MApping
    string ans;
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] == ' ')
        {
            ans.push_back(' ');
        }
        else
        {
            ans.push_back(mapping[message[i]]);
        }
    }
    return ans;
}

int main()
{
    string key;
    string message;
    cout << "Input key: " << endl;
    getline(cin, key);
    cout << "Input message: " << endl;
    getline(cin, message);
    cout << "The decoded message is: " << endl;
    cout << decodeMessage(key, message);
    return 0;
}