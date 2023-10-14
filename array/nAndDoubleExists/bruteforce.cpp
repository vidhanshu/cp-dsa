/**
 * @author vidhanshu borade
 * @date 11/10/23
 * Given an array nums of integers, check if there exist two indices i and j such that :
 * i != j
 * 0 <= i, j < nums.length
 * nums[i] == 2 * nums[j]
 *
 * Example 1:
 * Input: nums = [10,2,5,3]
 * Output: true
 * Explanation: For i = 0 and j = 2, nums[i] == 10 == 2 * 5 == 2 * nums[j]
 *
 * Example 2:
 * Input: nums = [3,1,7,11]
 * Output: false
 * Explanation: There is no i and j that satisfy the conditions.
 * Constraints:
 *
 * 2 <= nums.length <= 500
 * -103 <= nums[i] <= 103
 */

/**
 * Approach:
 * use two nested for loops to determine whether i and j exists such that it satisfies given constraints
 *
 * TC: O(n^2) - 500 * 500 ~ 10^4
 * SC: O(1)
 */

#define inputAr(ar)    \
    for (auto &it : ar) \
        cin >> it;

#include <bits/stdc++.h>
using namespace std;

bool checkIfExist(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i != j && (nums[i] == 2 * nums[j] || nums[j] == 2 * nums[i]))
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
    vector<int> nums(n);
    inputAr(nums);
    cout << checkIfExist(nums);
}