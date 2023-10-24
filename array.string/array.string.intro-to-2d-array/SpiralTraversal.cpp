/**
 * @author vidhanshu borade
 * @date 21/10/2023
 *
 * Problem:
 * We can keep 4 pointers, top, bottom, left, right - which we will use to create the ranges on which we will traversing
 * and we will traverse over a range and will push the elm to the answer array
 *
 * will keep doing this until our row and col are inside bound
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

vector<int> spiralOrder(vector<vector<int>> &mat)
{
    vector<int> ans;
    int m = mat.size();
    int n = mat[0].size();
    int top = 0, left = 0, right = n - 1, bottom = m - 1;

    while (top <= bottom && left <= right)
    {
        // moving to the right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(mat[top][i]);
        }
        top++;
        // moving to the down
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(mat[i][right]);
        }
        right--;
        // moving to the left
        // after top++, top might have cross bottom
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }
        // after right-- right might have cross left
        if (left <= right)
        {
            // moving to the up
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    outputAr(spiralOrder(mat));
}