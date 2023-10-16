/**
 * @author vidhanshu borade
 * @date 10/10/2023
 *
 */

/**
 * Approach:
 * - Use extra space O(n) i.e. vector<int> ans;
 * - Loop over given array, if(ar[i] == 0) then push 2 zeros to the ans other wise simply push the nums[i]
 * - do this until the size of ans becomes n
 * - copy back the ans to nums, done ✅
 *
 * - TC: O(2n) ~ O(n)
 * - SC: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

void duplicateZeros(vector<int> &nums)
{
    // if all elements are 0
    if (all_of(nums.begin(), nums.end(), [](int a)
               { return !a; }))
    {
        return;
    }

    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n && ans.size() <= n; i++)
    {
        // if 0 then push 2 zeros
        if (!nums[i])
        {
            ans.push_back(0);
            ans.push_back(0);
        }
        // if not push current element
        else
        {
            ans.push_back(nums[i]);
        }
    }

    // copy the ans to nums back
    for (int i = 0; i < n; i++)
    {
        nums[i] = ans[i];
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &it : nums)
        cin >> it;

    duplicateZeros(nums);

    for (auto &it : nums)
        cout << it << " ";
}