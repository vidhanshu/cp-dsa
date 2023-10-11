/**
 * @author vidhanshu borade
 * @date 11/10/23
 * Given an array arr of integers, check if there exist two indices i and j such that :
 * i != j
 * 0 <= i, j < arr.length
 * arr[i] == 2 * arr[j]
 *
 * Example 1:
 * Input: arr = [10,2,5,3]
 * Output: true
 * Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
 *
 * Example 2:
 * Input: arr = [3,1,7,11]
 * Output: false
 * Explanation: There is no i and j that satisfy the conditions.
 * Constraints:
 *
 * 2 <= arr.length <= 500
 * -103 <= arr[i] <= 103
 */

/**
 * Approach:
 * use two nested for loops to determine whether i and j exists such that it satisfies given constraints
 *
 * TC: O(n^2) - 500 * 500 ~ 10^4
 * SC: O(1)
 * BEATS: 100% c++ users timewise
 */

#define input_ar(ar)    \
    for (auto &it : ar) \
        cin >> it;
#define output_ar(ar)   \
    for (auto &it : ar) \
        cout << it << " ";

#include <bits/stdc++.h>
using namespace std;

bool checkIfExist(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (i != j && (arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i]))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    input_ar(ar);
    cout << checkIfExist(ar);
}