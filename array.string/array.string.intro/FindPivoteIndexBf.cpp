/**
 * @author vidhanshu borade
 * @date 17/10/2023
 *
 * Problem:
 * Given an array of integers nums, calculate the pivot index of this array.
 * The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
 * If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
 * Return the leftmost pivot index. If no such index exists, return -1.
 *
 * Example 1:
 * Input: nums = [1,7,3,6,5,6]
 * Output: 3
 * Explanation:
 * The pivot index is 3.
 * Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
 * Right sum = nums[4] + nums[5] = 5 + 6 = 11
 *
 * Example 2:
 * Input: nums = [1,2,3]
 * Output: -1
 * Explanation:
 * There is no index that satisfies the conditions in the problem statement.
 *
 * Example 3:
 * Input: nums = [2,1,-1]
 * Output: 0
 * Explanation:
 * The pivot index is 0.
 * Left sum = 0 (no elements to the left of index 0)
 * Right sum = nums[1] + nums[2] = 1 + -1 = 0
 *
 * Constraints:
 * 1 <= nums.length <= 10^4
 * -1000 <= nums[i] <= 1000
 */

/**
 * Approach:
 * For each index find the sum of it's previos elems and next elems and check if they are equal
 * if equal then return index
 * else continue
 * if index not found then return -1 at the end
 *
 * TC: O(n^2) - for every elem we are iterating over an array - 10^8 iterations
 * SC: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    const int N = nums.size();

    for (int i = 0; i < N; i++)
    {
        int leftSum = 0;
        int rightSum = 0;

        // find left sum
        if (i != 0)
        {
            for (int j = 0; j < i; j++)
            {
                leftSum += nums[j];
            }
        }
        // find right sum
        if (i != N - 1)
        {
            for (int j = i + 1; j < N; j++)
            {
                rightSum += nums[j];
            }
        }
        // compare if same return i;
        if (leftSum == rightSum)
            return i;
    }

    // if no pivote found
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (auto &it : ar)
        cin >> it;

    cout << pivotIndex(ar) << '\n';
}