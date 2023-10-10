/**
 * @author vidhanshu borade
 * @date 09/10/2023
 *
 * Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.
 * Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.
 *
 * Example 1:
 * Input: arr = [1,0,2,3,0,4,5,0]
 * Output: [1,0,0,2,3,0,0,4]
 * Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
 *
 * Example 2:
 * Input: arr = [1,2,3]
 * Output: [1,2,3]
 * Explanation: After calling your function, the input array is modified to: [1,2,3]
 *
 * Constraints:
 * 1 <= arr.length <= 104
 * 0 <= arr[i] <= 9
 *
 * Approach:
 * Bruteforce: 
 * - Loop over given array:
 *      - if 0 is found, shift everything from i to i + 1 by 1 place to right
 *      - increament i in this case by 2 instead of by 1 to skip the recently added 0
 * - Time: O(n*n)
 * - Space: O(1)
 * - Leetcode runtime: ~75ms
 */

#include <bits/stdc++.h>
using namespace std;

void duplicateZeros(vector<int> &arr)
{
    // if all elements are 0
    if (all_of(arr.begin(), arr.end(), [](int a)
               { return !a; }))
    {
        return;
    }

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        // if arr[i] is 0
        if (!arr[i])
        {
            // shift everything from i to n-1 by one place right
            // this must be done from end to start, otherwise everything will become 0
            // try dry running once to make it clear :-)
            for (int j = n - 1; j > i; j--)
            {
                arr[j] = arr[j - 1];
            }
            // incrementing by 2 (+1 will be done by for loop) to skip recantly added 0
            i++;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (auto &it : ar)
        cin >> it;

    duplicateZeros(ar);

    for (auto &it : ar)
        cout << it << " ";
}