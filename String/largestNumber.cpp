#include <bits/stdc++.h>
using namespace std;

bool myComp(string a, string b)
{
    string t1 = a + b;
    string t2 = b + a;
    return t1 > t2;
}
// strings are compared lexicographically,
// so if t1 > t2 this means the current order
// is right and we will returen true
string largestNumber(vector<int> &nums)
{
    // converting all numbers to strings
    vector<string> strNum;
    for (auto n : nums)
    {
        strNum.push_back(to_string(n));
    }
    sort(strNum.begin(), strNum.end(), myComp);
    if (strNum[0] == "0")
    {
        return "0";
    }
    string ans = "";
    for (auto s : strNum)
    {
        ans += s;
    }
    return ans;
}

int main()
{
    int n;
    std::cout << "Input the number for array " << endl;
    cin >> n;
    vector<int> nums(n);
    std::cout << "Input the number for array " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Largest number created from the numbers is " << endl;
    std::cout << largestNumber(nums);
    return 0;
}