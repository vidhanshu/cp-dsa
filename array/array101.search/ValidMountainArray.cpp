/**
 * @author vidhanshu borade
 * @date 11/10/23
 *
 * problem:
 * Given an array of integers arr, return true if and only if it is a valid mountain array.
 * Recall that arr is a mountain array if and only if:
 * arr.length >= 3
 *
 * There exists some i with 0 < i < arr.length - 1 such that:
 * arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
 * arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
 *
 * Example 1:
 * Input: arr = [2,1]
 * Output: false
 *
 * Example 2:
 * Input: arr = [3,5,5]
 * Output: false
 *
 * Example 3:
 * Input: arr = [0,3,2,1]
 * Output: true
 *
 * Constraints:
 * 1 <= arr.length <= 104
 * 0 <= arr[i] <= 104
 */

/**
 * Approach:
 * Simple find the number of peaks i.e. count how many such scenarios are 
 * there in which
 * arr[i] > arr[i + 1] && arr[i] > arr[i - 1]
 * 
 * There are 3 edge cases we need to handle manually
 * 1) When length is < 3 return false
 * 2) if any two consecutive elements are same then return false(it violets rule)
 * 3) if 0th element is greater than 1th or (n-1)th element is greater than (n-2)th
 *    return false directly, since this also violets rule.
 * if no. of peaks == 1 then true else false
 * 
 * TC: O(n)
 * SC: O(1)
 */

#define inputAr(ar)    \
    for (auto &it : ar) \
        cin >> it;
#define outputAr(ar)   \
    for (auto &it : ar) \
        cout << it << " ";

#include <bits/stdc++.h>
using namespace std;

bool validMountainArray(vector<int> &arr)
{
 
    const int n = arr.size();

    if (n < 3)
        return false;

    if (arr[0] > arr[1] || arr[n - 1] > arr[n - 2])
    {
        return false;
    }

    int peakCount = 0;

    for (int i = 1; i < n - 1; i++)
    {
        // if any two consecutive elm same return false
        if (arr[i - 1] == arr[i] || arr[i] == arr[i + 1])
            return false;

        (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) && peakCount++;

        // little optimization
        if (peakCount > 1)
            return false;
    }

    return peakCount == 1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (auto &it : ar)
        cin >> it;

    cout << validMountainArray(ar);
}