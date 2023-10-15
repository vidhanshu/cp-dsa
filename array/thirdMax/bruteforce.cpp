/**
 * @author vidhanshu borade
 * @date 15/10/23
 *
 * Problem description:
 * Given an integer array nums, return the third distinct maximum number in this array. If the
 * third maximum does not exist, return the maximum number.
 *
 * Example 1:
 * Input: nums = [3,2,1]
 * Output: 1
 * Explanation:
 * The first distinct maximum is 3.
 * The second distinct maximum is 2.
 * The third distinct maximum is 1.
 *
 * Example 2:
 * Input: nums = [1,2]
 * Output: 2
 * Explanation:
 * The first distinct maximum is 2.
 * The second distinct maximum is 1.
 * The third distinct maximum does not exist, so the maximum (2) is returned instead.
 *
 * Example 3:
 * Input: nums = [2,2,3,1]
 * Output: 1
 * Explanation:
 * The first distinct maximum is 3.
 * The second distinct maximum is 2 (both 2's are counted together since they have the same value).
 * The third distinct maximum is 1.
 *
 * Constraints:
 * 1 <= nums.length <= 104
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 * Follow up: Can you find an O(n) solution?
 */

/**
 * Approach:
 * Use set to find the third max elem
 *
 * TC: O(n.logn)
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

int thirdMax(vector<int> &nums)
{
    set<int> st(nums.begin(), nums.end());
    if (st.size() < 3)
    {
        auto it = st.end();
        // decrement it once, since st.end() returns iterator to th next
        // location of the last elm in set
        it--;
        return *it;
    }
    auto it = st.end();
    // decrement iterator 3 times so that it can point to 3rd elem from end
    return *(--(--(--(it))));
}
int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    inputAr(ar);
    cout << thirdMax(ar);
}