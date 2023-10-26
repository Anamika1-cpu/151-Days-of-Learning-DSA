#include <bits/stdc++.h>
using namespace std;

void removeOccurence(string &s, string &part)
{
    // find will find the position of part string in s
    int found = s.find(part);
    // find will return npos if the part is not found in s
    // So, it means if it is not returning npos, part is found in s
    if (found != string::npos)
    {
        string left_part = s.substr(0, found);
        // we can remove the part by finding it's left
        // and right part and then concatenating them
        string right_part = s.substr(found + part.length(), s.size());
        s = left_part + right_part;
        removeOccurence(s, part);
    }
    else
    {
        // base case of recursion
        // here we reached only when all occurences
        // of part is removed and found will return npos

        return;
    }
}
int main()
{
    string s = "hello, world, hello, universe";
    string part = "hello";
    cout << "After removing all occurences from " << s << endl;
    removeOccurence(s, part);
    cout << "Left string is " << s << endl;
    return 0;
}