/**
 * @author vidhanshu borade
 * @date 15/10/23
 *
 * Problem description:
 * Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
 *
 * Example 1:
 * Input: nums = [4,3,2,7,8,2,3,1]
 * Output: [5,6]
 *
 * Example 2:
 * Input: nums = [1,1]
 * Output: [2]
 *
 * Constraints:
 * n == nums.length
 * 1 <= n <= 105
 * 1 <= nums[i] <= n
 *
 * Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 */

/**
 * Approach:
 * use unordered_set,
 * unordered_set will help us to find if elm present in it or not in O(1)
 *
 * TC: θ(n), O(nums.size() * set.size())
 * SC: O(ust.size())
 */

#define inputAr(ar)     \
    for (auto &it : ar) \
        cin >> it;
#define outputAr(ar)    \
    for (auto &it : ar) \
        cout << it << " ";

#include <bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    unordered_set<int> ust(nums.begin(), nums.end());
    // will not be considered as extra space
    vector<int> ans;

    for (int i = 1; i <= nums.size(); i++)
    {
        // avg case O(1) but worst case O(ust.size())
        if (ust.find(i) == ust.end())
        {
            ans.push_back(i);
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
    outputAr(findDisappearedNumbers(ar));
}
