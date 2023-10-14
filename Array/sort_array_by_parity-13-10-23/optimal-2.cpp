/**
 * @author vidhanshu borade
 * @date 13/10/23
 */

/**
 * Approach:
 *
 * i = 0, j = n - 1
 * while i < j:
 * Skip all even's from start and skip all odd's from end
 * now for sure i will stop on odd and j will stop on even so swap them(swap only if i < j)
 *
 * TC: O(n)
 * SC: O(1)
 */

#define input_ar(ar)    \
    for (auto &it : ar) \
        cin >> it;
#define output_ar(ar)   \
    for (auto &it : ar) \
        cout << it << " ";

#include <bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParity(vector<int> &nums)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int n = nums.size();
    int i = 0, j = n - 1;

    while (i < j)
    {
        // skip all evens from start
        while (i < n && !(nums[i] & 1))
            i++;
        // skip all odds from end
        while (j >= 0 && (nums[j] & 1))
            j--;

        // swap ith odd and jth even element
        if (i < j)
            swap(nums[i], nums[j]);
    }

    return nums;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    input_ar(ar);
    output_ar(sortArrayByParity(ar));
}