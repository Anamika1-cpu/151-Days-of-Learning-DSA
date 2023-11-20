#include <bits/stdc++.h>
using namespace std;

int garbage_collect(vector<string> &garbage, vector<int> &travel)
{
    // Variables to keep track of pick time of garbage of particular
    //  type of garbage
    int pickP = 0;
    int pickM = 0;
    int pickG = 0;

    // Variables to keep track of travel time of garbage of particular
    //  type of garbage
    int travelTimeP = 0;
    int travelTimeM = 0;
    int travelTimeG = 0;

    // variables to get last index of particular type of garbage
    int lastIndexP = 0;
    int lastIndexM = 0;
    int lastIndexG = 0;

    // Calculate Pick time
    for (int i = 0; i < garbage.size(); i++)
    {
        string curr = garbage[i];
        for (int j = 0; j < curr.length(); j++)
        {
            char currChar = curr[j];
            if (currChar == 'P')
            {
                pickP++;
                lastIndexP = i;
            }
            else if (currChar == 'M')
            {
                pickM++;
                lastIndexM = i;
            }
            else
            {
                pickG++;
                lastIndexG = i;
            }
        }
    }
    // Calculate travel time
    for (int i = 0; i < lastIndexG; i++)
    {
        travelTimeG += travel[i];
    }
    for (int i = 0; i < lastIndexM; i++)
    {
        travelTimeM += travel[i];
    }
    for (int i = 0; i < lastIndexP; i++)
    {
        travelTimeP += travel[i];
    }
    int ans = (pickG + travelTimeG) + (pickM + travelTimeM) +
              (pickP + travelTimeP);

    return ans;
}

int main()
{
    cout << "Input the size of garbage vector" << endl;
    int n;
    cin >> n;
    vector<string> garbage(n);
    cout << "Input the garbage vector of strings" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> garbage[i];
    }
    cout << "Input the size of travel time vector" << endl;
    int t;
    cin >> t;
    vector<int> travel(t);
    cout << "Input the travel time vector " << endl;
    for (int i = 0; i < t; i++)
    {
        cin >> travel[i];
    }
    cout << "Minimum time to collect all the garbage will be " << endl;
    cout << garbage_collect(garbage, travel) << endl;
    return 0;
}