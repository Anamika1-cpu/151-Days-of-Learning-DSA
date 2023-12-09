#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num)
{
    string romanValues[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string ans = "";
    for (int i = 0; i < 13; i++)
    {
        while (num >= values[i])
        {
            ans += romanValues[i];
            num -= values[i];
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Input the number to convert in Roman format" << endl;
    cin >> n;
    cout << "After converting the number in Roman is" << endl;
    string a = intToRoman(n);
    cout << a << endl;
    return 0;
}