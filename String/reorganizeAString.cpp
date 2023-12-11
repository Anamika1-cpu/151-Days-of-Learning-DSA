#include <bits/stdc++.h>
using namespace std;

string rorganizeString(string s)
{
    // here our idea of solving this problem is first find the
    //  character which is occuring most number of times and then
    //  arrange that character first alternatively and then arrange
    // the remaining characters

    int hash[26] = {0};
    // creating count of all characters present in string
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++;
    }

    // finding the most occurent character
    char most_occurent_char;
    int most_occurent_count = INT_MIN;
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > most_occurent_count)
        {
            most_occurent_count = hash[i];
            most_occurent_char = i + 'a';
        }
    }
    int index = 0;
    while (most_occurent_count > 0 && index < s.size())
    {
        s[index] = most_occurent_char;
        most_occurent_count--;
        index += 2;
        // here we are increasing the index by 2
        // because we have to fill the char alternatively
    }
    if (most_occurent_count != 0)
    {
        return "";
    }
    hash[most_occurent_char - 'a'] = 0;

    // placing rest of the char
    for (int i = 0; i < 26; i++)
    {
        while (hash[i] > 0)
        {
            index = index >= s.size() ? 1 : index;
            s[index] = i + 'a';
            hash[i]--;
            index += 2;
        }
    }
    return s;
}

int main()
{
    string str;
    cout << "Input the string" << endl;
    cin >> str;
    cout << "After reorganizing the string is" << endl;
    string ans = rorganizeString(str);
    cout << ans << endl;
    return 0;
}