/**
 * @author vidhanshu borade
 * @date 11/10/23
*/

/**
 * Approach:
 * The first element in the array is at it's correct position, now for second element we need to skip all the
 * occurences of the first element, thus we will stop on some unique elm store it to second, and now for 
 * finding the third elm skip all occurences of second elm and so on....
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

int removeDuplicates(vector<int> &nums)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i = 0;
    int n = nums.size();
    for (int j = 0; j < n; j++)
    {
        int curr = nums[j];
        nums[i++] = curr;
        while (j < nums.size() && nums[j] == curr)
            j++;
        // j++ will happen in for loop hence, doing j-- to cancel that out
        j--;
    }
    return i;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    input_ar(ar);
    removeDuplicates(ar);
    output_ar(ar);
}