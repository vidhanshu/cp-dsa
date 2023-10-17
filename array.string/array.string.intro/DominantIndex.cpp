/**
 * @author vidhanshu borade
 * @date 17/10/2023
 *
 * Problem:
 * You are given an integer array nums where the largest integer is unique.
 * Determine whether the largest element in the array is at least twice as much as every other number in the array. If it is, return the index of the largest element, or return -1 otherwise.
 *
 * Example 1:
 * Input: nums = [3,6,1,0]
 * Output: 1
 * Explanation: 6 is the largest integer.
 * For every other number in the array x, 6 is at least twice as big as x.
 * The index of value 6 is 1, so we return 1.
 *
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: -1
 * Explanation: 4 is less than twice the value of 3, so we return -1.
 *
 * Constraints:
 * 2 <= nums.length <= 50
 * 0 <= nums[i] <= 100
 * The largest element in nums is unique.
 */

/**
 * Approach:
 * Find the maxElm and check against every nums[i](except maxElm itself) if maxElm >= 2*nums[i]
 *
 * TC: O(2n) = O(n)
 * SC: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

int dominantIndex(vector<int> &nums)
{
    const int N = nums.size();
    // maxElm will exists for sure, that to unique (given in question)
    const int maxElmIdx = max_element(nums.begin(), nums.end()) - nums.begin();
    const int maxElm = nums[maxElmIdx];

    // if all elm except maxElm are not following the condition
    // maxElm >= 2*a
    if (!all_of(nums.begin(), nums.end(), [&](int a)
                { return a == maxElm ? true : maxElm >= 2 * a; }))
        return -1;

    return maxElmIdx;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (auto &it : ar)
        cin >> it;

    cout << dominantIndex(ar) << '\n';
}