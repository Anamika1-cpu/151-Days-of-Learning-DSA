#include <bits/stdc++.h>
using namespace std;

int main()
{

    char s[] = {'a',
                'a',
                'b',
                'b',
                'b',
                'b',
                'c',
                'c',
                'c'};
    int n = 9;
    vector<string> v;
    vector<string> result;
    string temp = "";
    for (int i = 0; i < n; i++)
    {
        temp += s[i];
        if (i == n - 1 || s[i] != s[i + 1])
        {

            v.push_back(temp);
            temp = "";
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        string a = "";
        a = v[i][0] + to_string(v[i].size());
        result.push_back(a);
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}