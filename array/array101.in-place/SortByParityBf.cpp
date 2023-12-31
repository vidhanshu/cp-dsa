/**
 * @author vidhanshu borade
 * @date 13/10/23
 *
 * Problem description:
 * Given an integer array nums, move all the even integers at the beginning
 * of the array followed by all the odd integers.
 * Return any array that satisfies this condition.
 *
 * Example 1:
 * Input: nums = [3,1,2,4]
 * Output: [2,4,3,1]
 * Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also
 * be accepted.
 *
 * Example 2:
 * Input: nums = [0]
 * Output: [0]
 *
 * Constraints:
 * 1 <= nums.length <= 5000
 * 0 <= nums[i] <= 5000
 */

/**
 * Approach:
 * Use extra space and 2 pointer approach collectively to solve the problem
 *
 * TC: O(n)
 * SC: O(n)
 */

#define inputAr(ar)    \
    for (auto &it : ar) \
        cin >> it;
#define outputAr(ar)   \
    for (auto &it : ar) \
        cout << it << " ";

#include <bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParity(vector<int> &nums)
{
 
    const int n = nums.size();
    vector<int> ans(n);
    int i = 0, j = n - 1;

    // iterate over an array nums
    for (auto &it : nums)
    {
        // if it is odd, store it from the end
        if (it & 1)
        {
            ans[j--] = it;
        }
        // if it is even, store it from the start
        else
        {
            ans[i++] = it;
        }
    }

    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    inputAr(ar);
    outputAr(sortArrayByParity(ar));
}