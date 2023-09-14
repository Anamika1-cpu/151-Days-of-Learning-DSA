#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(int n)
{
    int decimal = 0;
    int i = 0;

    while (n != 0)
    {
        int bit = n % 10;
        decimal = decimal + bit * pow(2, i++);
        n = n / 10;
    }

    return decimal;
}

int main()
{
    int n;
    cout << "Enter Binary number" << endl;
    cin >> n;
    cout << "Decimal of " << n << " is " << binaryToDecimal(n) << endl;
    return 0;
}