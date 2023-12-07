#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    map<string, vector<string>> mp;
    for (auto &str : strs)
    {
        string s = str;
        sort(s.begin(), s.end());
        mp[s].push_back(str);
    }

    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        ans.push_back(it->second);
    }
    return ans;
}

int main()
{

    vector<string> arr;
    arr.push_back("eat");
    arr.push_back("tea");
    arr.push_back("nat");
    arr.push_back("tan");
    arr.push_back("ate");
    arr.push_back("bat");

    vector<vector<string>> ans = groupAnagrams(arr);
    cout << "The group of anagram is" << endl;
    for (auto a : ans)
    {
        for (auto str : a)
        {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}