/**
 * @author vidhanshu borade
 * @date 21/10/2023
 *
 * Problem:
 * We can move in either diagonally up direction (row--, col++) or diagonally down direction(row++, col--).
 * we can keep direction variable which will keep track of in which direction we are moving in diaognally
 * and after completion of diagonal movememnt towards up, we can either move to right or down
 *  1) we will move right if after moving our position will still be inside bound
 *  2) we will move down if after moving our position will be outside bound
 *  similarly for down diagonal movement completion, we can either move down or right
 *  1) we will move down if after moving our position will still be inside bound
 *  2) we will move right if after moving our position will be outside bound
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

vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
    vector<int> ans;
    int m = mat.size();
    int n = mat[0].size();
    int row = 0, col = 0;
    bool dir = true; // true means up and false means down

    while (row < m && col < n)
    {
        // if moving diagonally up
        if (dir)
        {
            while (row > 0 && col < n - 1)
            {
                ans.push_back(mat[row][col]);
                row--;
                col++;
            }
            // since when above while loop will run it's last iteration it will decrement row
            // and increment col keeping both of them inside bound, hence will push the last elm in that diagonal
            ans.push_back(mat[row][col]);
            // if col is last column move down
            if (col == n - 1)
            {
                row++;
            }
            // else move right
            else
            {
                col++;
            }
        }
        // if moving diagonally down
        else
        {
            // until we reach down
            // not keeping condition like col >= 0 or row < m
            // because it will make col or row to go out of bound
            while (col > 0 && row < m - 1)
            {
                ans.push_back(mat[row][col]);
                row++;
                col--;
            }
            // since when above while loop will run it's last iteration it will increment row
            // and decrement col keeping both of them inside bound, hence will push the last elm in that diagonal
            ans.push_back(mat[row][col]);
            // if row is last row can't move down, hence move right
            if (row == m - 1)
            {
                col++;
            }
            // else move down
            else
            {
                row++;
            }
        }
        // change direction each time
        dir = !dir;
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
    outputAr(findDiagonalOrder(mat));
}