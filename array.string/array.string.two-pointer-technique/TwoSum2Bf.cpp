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
 * Approach1: (below code)
 * Since the array is sorted we can take advantage of it,
 * let's say the target is T, one by one we can assume each element to be firstInteger and then using binary search we can look for secondInteger such that the indices of both are different
 * let's say the firstInteger to be f1 then f2 = target - f1
 *
 * Approach2:
 * We can also use unordered_map/hashtable to keep track of already occured elms and there indexes, but as mentioend in the question don't have to use extra space this approach isn't correct.
 * 
 * TC: O(nlogn)
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
    for (int i = 0; i < N; i++)
    {
        // assume, current elm to be firstNum
        int firstNum = numbers[i];
        // this is required secondNum
        int secondNum = target - firstNum;

        vector<int> ans;

        // apply binary search
        int lo = 0, hi = numbers.size() - 1, mid;
        while (lo <= hi)
        {
            mid = (lo + hi) >> 1;

            if (numbers[mid] == secondNum && mid != i)
            {
                ans.push_back(i + 1);
                ans.push_back(mid + 1);
                // sort before returning, it's O(1)
                sort(ans.begin(), ans.end());
                return ans;
            }
            else if (secondNum > numbers[mid])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
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