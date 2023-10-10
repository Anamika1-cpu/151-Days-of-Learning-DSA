#include <bits/stdc++.h>
using namespace std;

vector<int> sprialPrint(vector<vector<int>> &v)
{
    int m = v.size();
    int n = v[0].size();
    int total_elements = m * n;
    int count = 0;

    int starting_row = 0;
    int ending_col = m - 1;
    int ending_row = n - 1;
    int starting_col = 0;

    vector<int> ans;

    while (count < total_elements)
    {
        // printing starting row -------->
        for (int i = starting_col; i <= ending_col && count < total_elements; i++)
        {
            ans.push_back(v[starting_row][i]);
            count++;
        }
        starting_row++;
        // printing ending col   |
        //                       |
        //                       ↓
        for (int i = starting_row; i <= ending_row && count < total_elements; i++)
        {
            ans.push_back(v[i][ending_col]);
            count++;
        }
        ending_col--;
        // printing ending row  <--------
        for (int i = ending_col; i >= starting_col && count < total_elements; i--)
        {
            ans.push_back(v[ending_row][i]);
            count++;
        }
        ending_row--;
        // printing starting col   ↑
        //                         |
        //                         |
        for (int i = ending_row; i >= starting_row && count < total_elements; i--)
        {
            ans.push_back(v[i][starting_col]);
            count++;
        }
        starting_col++;
    }
    return ans;
}

int main()
{
    vector<vector<int>> vect{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    vector<int> a = sprialPrint(vect);
    cout << "Spiral print of a given matrix is " << endl;
    for (auto i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
