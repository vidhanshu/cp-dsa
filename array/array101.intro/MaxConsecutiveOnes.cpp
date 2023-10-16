/**
 * @author vidhanshu borade
 * @date 09/10/2023
 *
 * Problem: Given a binary array nums, return the maximum number of consecutive 1's in the array.
 *
 * Example 1:
 * Input: nums = [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
 *
 * Example 2:
 * Input: nums = [1,0,1,1,0,1]
 * Output: 2
 *
 * Constraints:
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 */

/**
 * Approach:
 * initialize two variables :
 * count = 0 - stores the count of 1's and will reset if 0 is found on current index
 * maxTillNow = 0 - to store the result i.e. max consecutive one's till now
 *
 * we will iterate over an given array and will do:
 * - if the current element is 1 then increment count by 1 and do maxTillNow = max(maxTillNow, count)
 * - elif current element is 0 reset the count to 0, since streak is broken
 */

#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &ar)
{
    int count = 0;
    int maxTillNow = 0;

    int n = ar.size();

    for (int i = 0; i < n; i++)
    {
        const int it = ar[i];
        // if it is 1
        if (it)
        {
            count++;
            // max count till now
            maxTillNow = max(maxTillNow, count);
        }
        // reset count
        else
        {
            count = 0;
        }
    }

    return maxTillNow;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (auto &it : ar)
        cin >> it;

    cout << findMaxConsecutiveOnes(ar) << '\n';
}