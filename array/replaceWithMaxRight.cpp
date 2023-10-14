/**
 * @author vidhanshu borade
 * @date 11/10/23
 *
 * problem:
 * Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.
 * After doing so, return the array.
 * Example 1:
 * Input: arr = [17,18,5,4,6,1]
 * Output: [18,6,6,6,1,-1]
 * Explanation:
 * - index 0 --> the greatest element to the right of index 0 is index 1 (18).
 * - index 1 --> the greatest element to the right of index 1 is index 4 (6).
 * - index 2 --> the greatest element to the right of index 2 is index 4 (6).
 * - index 3 --> the greatest element to the right of index 3 is index 4 (6).
 * - index 4 --> the greatest element to the right of index 4 is index 5 (1).
 * - index 5 --> there are no elements to the right of index 5, so we put -1.
 * Example 2:
 * Input: arr = [400]
 * Output: [-1]
 * Explanation: There are no elements to the right of index 0.
 */

/**
 * Approach:
 * 1) Bruteforce is very simple for every element just find the largest on right, but
 *    That would be O(n^2) solution not much effective
 * TC: O(n^2)
 * SC: O(1)
 *
 * 2) We can use prefix sum/running sum approach, but instead of sum we will keep track of
 *    max till (i - 1)th index and will replace ith element with that.
 * TC: O(n)
 * SC: O(1)
 */

#define inputAr(ar)     \
    for (auto &it : ar) \
        cin >> it;
#define outputAr(ar)    \
    for (auto &it : ar) \
        cout << it << " ";

#include <bits/stdc++.h>
using namespace std;

vector<int> replaceElements(vector<int> &arr)
{
    int maxTillI = INT_MIN;
    int n = arr.size();

    for (int i = n - 1; i >= 0; i--)
    {
        // preservering current elm, since will get overriden by max / -1
        int current = arr[i];

        // only happens when i = n - 1
        if (maxTillI == INT_MIN)
        {
            arr[i] = -1;
        }
        else
        {
            arr[i] = maxTillI;
        }

        // update maxTillI
        maxTillI = max(maxTillI, current);
    }

    return arr;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    inputAr(ar);

    outputAr(replaceElements(ar));
}