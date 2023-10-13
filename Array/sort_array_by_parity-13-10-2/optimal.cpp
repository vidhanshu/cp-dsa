/**
 * @author vidhanshu borade
 * @date 13/10/23
 */

/**
 * Approach:
 * Move all odd's to the end similar to the move all zero's to the end
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

    // move j to the even from end
    while (j >= 0 && (nums[j] & 1))
        j--;

    while (i < j)
    {
        // if num is odd
        if (nums[i] & 1)
        {
            // move it to the end
            swap(nums[i], nums[j]);

            // move j to the even from end
            while (j >= 0 && (nums[j] & 1))
                j--;
        }
        // increment i
        i++;
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