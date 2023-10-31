#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int n = row * col;

    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        int rowIndex = mid / col;
        int colIndex = mid % col;
        if (matrix[rowIndex][colIndex] == target)
        {
            return true;
        }
        else if (matrix[rowIndex][colIndex] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    bool ans = searchMatrix(matrix, 35);
    if (ans == 1)
    {
        cout << "Element is present in matrix " << endl;
    }
    else
    {
        cout << "Element is not present in matrix" << endl;
    }
    return 0;
}
