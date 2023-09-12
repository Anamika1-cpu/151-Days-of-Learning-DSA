#include <bits/stdc++.h>
using namespace std;

int decimalToBinary(int n)
{
    int binaryNum = 0;
    int i = 1;

    while (n > 0)
    {
        int bit = n % 2;
        binaryNum += bit * i;
        n = n / 2;
        i *= 10;
    }

    return binaryNum;
}

int main()
{
    int n;
    cout << "Enter Decimal number" << endl;
    cin >> n;
    cout << "Binary of " << n << " is " << decimalToBinary(n) << endl;
    return 0;
}