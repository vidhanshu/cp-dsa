/**
 * @author vidhanshu borade
 * @date 22/10/2023
 *
 * Problem:
 * colAbove = nums[i-1][j] // just make sure it is inside the bound
 * colDiagonallyAbove = nums[i-1][j-1] // just make sure it is inside the bound
 * nums[i][j] = colAbove + colDiagonallyAbove
 * 
 * for numRows = 4
 * 
 * |1| | | |
 * |1|1| | | 
 * |1|2|1| |
 * |1|3|3|1|
 */

/**
 * Approach:
 *
 * TC: O(m*n)
 * SC: O(1)
 */

#define outputAr(ar)    \
    for (auto &it : ar) \
        cout << it << " ";

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans(numRows);
    ans[0].push_back({1});

    for (int i = 1; i < numRows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int cellAbove = ans[i - 1].size() >= j + 1 ? ans[i - 1][j] : 0;
            int cellDiagonallyAbove = ans[i - 1].size() >= j && j - 1 >= 0 ? ans[i - 1][j - 1] : 0;
            ans[i].push_back(cellAbove + cellDiagonallyAbove);
        }
    }

    return ans;
}

int main()
{
    int numRows;
    cin >> numRows;
    vector<vector<int>> ans = generate(numRows);

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}