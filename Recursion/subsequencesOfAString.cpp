#include <bits/stdc++.h>
using namespace std;

void find_subsequence(string str, string output, int index)
{
    if (index >= str.length())
    {
        cout << output << "->" << endl;
        return;
    }
    // there are two possibility of every character either we INCLUDE it or EXCLUDE it

    // EXCLUDE
    find_subsequence(str, output, index + 1);
    // INCLUDE
    find_subsequence(str, output + str[index], index + 1);
}

int main()
{
    find_subsequence("abc", "", 0);
    return 0;
}
