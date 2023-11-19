#include <bits/stdc++.h>
using namespace std;

int findMinDifference(vector<string> &timePoints)
{
}
int main()
{
    vector<string> timePoints = {"23:59", "00:00"};
    int a1, a2, b1, b2;
    // for (int i = 0; i < timePoints.size(); i++)
    // {
    a1 = stoi(timePoints[0].substr(0, 2));
    b1 = stoi(timePoints[0].substr(3, 4));
    a2 = stoi(timePoints[1].substr(0, 2));
    b2 = stoi(timePoints[1].substr(3, 4));
    // }
    cout << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
    int totalMin1;
    int totalMin2;
    if (a1 != 0)
    {
        totalMin1 = (a1 * 60) + b1;
    }
    else
    {
        totalMin1 = (24 * 60) + b1;
    }
    if (a2 != 0)
    {
        totalMin2 = (a2 * 60) + b2;
    }
    else
    {
        totalMin2 = (24 * 60) + b2;
    }

    int ans = totalMin1 - totalMin2;
    if (ans < 0)
    {
        cout << 0 << endl;
    }
    cout
        << totalMin1 << totalMin2 << endl;
    cout << "ans " << ans << endl;
    return 0;
}