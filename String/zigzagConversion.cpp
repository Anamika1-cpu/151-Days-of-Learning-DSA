#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;
    vector<string> zigzag(numRows);    // we are creating the zigzag vector for saving pattern of numRows size
    int i = 0, row = 0, direction = 1; // means moving from Top to Bottom
    while (true)
    {
        if (direction)
        { // from this code we are filling the first numRows
            while (row < numRows && i < s.size())
            {
                zigzag[row].push_back(s[i]);
                row++;
                i++;
            }
            row = numRows - 2;
        }
        else
        { // here we are moving from bottom to top
            while (row >= 0 && i < s.size())
            {
                zigzag[row].push_back(s[i]);
                row--;
                i++;
            }
            row = 1;
        }
        if (i >= s.size())
            break;
        direction = !direction;
    }
    string ans = "";
    for (int i = 0; i < zigzag.size(); i++)
    {
        ans += zigzag[i];
    }
    return ans;
}

int main()
{
    string s;
    int numOfRows;
    cout << "Input the string " << endl;
    cin >> s;
    cout << "Input the number of rows " << endl;
    cin >> numOfRows;
    cout << "The Zigzag pattern of the given string is " << endl;
    string ans = convert(s, numOfRows);
    cout << ans << endl;
    return 0;
}