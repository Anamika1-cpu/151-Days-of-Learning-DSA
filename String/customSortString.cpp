#include <bits/stdc++.h>
using namespace std;

string s;
bool compare(char c1, char c2)
{
    return s.find(c1) < s.find(c2);
}
string custom_string(string str, string order)
{
    s = order;
    sort(str.begin(), str.end(), compare);
    return str;
}

int main()
{
    string s;
    cout << "Input the string" << endl;
    cin >> s;
    string order;
    cout << "Input the order" << endl;
    cin >> order;
    string ans = custom_string(s, order);
    cout << "The string after cutomization is " << endl;
    cout << ans;
    return 0;
}