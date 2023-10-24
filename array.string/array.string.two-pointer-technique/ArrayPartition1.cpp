/**
 * @author vidhanshu borade
 * @date 24/10/2023
 *
 * Problem:
 * Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.
 *
 * Example 1:
 * Input: nums = [1,4,3,2]
 * Output: 4
 * Explanation: All possible pairings (ignoring the ordering of elements) are:
 * 1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
 * 2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
 * 3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
 * So the maximum possible sum is 4.
 *
 * Example 2:
 * Input: nums = [6,2,6,5,1,2]
 * Output: 9
 * Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.
 *
 * Constraints:
 * 1 <= n <= 104
 * nums.length == 2 * n
 * -10^4 <= nums[i] <= 10^4
 */

/**
 * Approach:
 * The approch that could think of is, the difference between paired elms shd be as min as possible, so to get such pairs we can sort the array
 * TC: O(nlogn)
 * SC: O(1)
 */

#include <bits/stdc++.h>

using namespace std;

int arrayPairSum(vector<int> &nums)
{
    // sort the array
    sort(nums.begin(), nums.end());

    int ans = 0;
    // take adjacent elems as a pair
    for (int i = 0; i < nums.size() - 1; i += 2)
    {
        ans += min(nums[i], nums[i + 1]);
    }
    return ans;
}

int main()
{
    int m;
    cin >> m;
    vector<int> nums(m);

    for (int i = 0; i < m; i++)
    {
        cin >> nums[i];
    }

    cout << arrayPairSum(nums);
}