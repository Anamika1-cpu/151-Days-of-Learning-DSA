#include <bits/stdc++.h>
using namespace std;

// Iterative approach
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int max_profit = 0;
    int min_price = prices[0];
    for (int i = 1; i < n; i++)
    {
        min_price = min(min_price, prices[i]);
        max_profit = max(max_profit, prices[i] - min_price);
    }
    return max_profit;
}

// Recursive Approach
int maxProfitrecursive(vector<int> &prices, int i, int &minPrice, int &maxProfit)
{

    // base condition
    if (i == prices.size())
    {
        return maxProfit;
    }
    // one solution
    if (prices[i] < minPrice)
    {
        minPrice = prices[i];
    }
    if (prices[i] - minPrice > maxProfit)
    {
        maxProfit = prices[i] - minPrice;
    }
    // Recursive call
    maxProfitrecursive(prices, i + 1, minPrice, maxProfit);
}
int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum profit: " << maxProfit(prices) << endl;
    int minPrice = INT_MAX;
    int maxP = INT_MIN;
    int recursiveAns = maxProfitrecursive(prices, 0, minPrice, maxP);
    return 0;
}
