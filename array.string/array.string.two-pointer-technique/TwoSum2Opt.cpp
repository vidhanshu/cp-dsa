/**
 * @author vidhanshu borade
 * @date 24/10/2023
 *
 * Problem:
 * Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 < numbers.length.
 *
 * Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
 *
 * The tests are generated such that there is exactly one solution. You may not use the same element twice.
 *
 * Your solution must use only constant extra space.
 *
 * Example 1:
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
 *
 * Example 2:
 * Input: numbers = [2,3,4], target = 6
 * Output: [1,3]
 * Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
 *
 * Example 3:
 * Input: numbers = [-1,0], target = -1
 * Output: [1,2]
 * Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
 *
 * Constraints:
 * 2 <= numbers.length <= 3 * 104
 * -1000 <= numbers[i] <= 1000
 * numbers is sorted in non-decreasing order.
 * -1000 <= target <= 1000
 * The tests are generated such that there is exactly one solution.
 */

/**
 * Approach:
 * The approach is to use two pointer approach, since the array is sorted we can keep two pointers 1 at start and 1 at end
 * we can keep track of current sum which inlcudes sum of number at lo position and hi position
 * if sum is greater than target it means we need to remove large number to reduce the sum, hence we will decrease hi
 * if sum is larger than target it means we need to add small number to increase sum, hence we will increase lo
 * 
 * TC: O(n)
 * SC: O(1)
 */

#define outputAr(ar)    \
    for (auto &it : ar) \
        cout << it << " ";
#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    const int N = numbers.size();

    int lo = 0, hi = numbers.size() - 1;

    while (lo < hi)
    {
        int currentSum = numbers[lo] + numbers[hi];
        if (currentSum == target)
        {
            return {lo + 1, hi + 1};
        }
        else if (currentSum > target)
        {
            hi--;
        }
        else
        {
            lo++;
        }
    }
    return {};
}

int main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;

    outputAr(twoSum(v, t));
}