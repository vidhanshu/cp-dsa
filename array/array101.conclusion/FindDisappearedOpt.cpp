/**
 * @author vidhanshu borade
 * @date 15/10/23
 */

/**
 * Approach:(Saw this approach from discussion section)
 * Approach is For each value in the array mark it's presence by making the number negative at that place in array
 * for example if the array is:
 * [2, 4, 4, 1]
 * for 2: we will make 1th location -ve, to mark 2's presence in the array: [2, -4, 4, 1]
 * for 4: we will make 3rd location -ve, to mark 4's presence in the array: [2, -4, 4, -1]
 * for 4: ignore since already marked
 * for 1: will make 0th location -ve, to mark 1's presence in the array: [-2, -4, 4, -1]
 * 
 * Now, indexes which are positive are the answers if we add 1 in them
 * in the above example ans will be [3] as (i + 1) = (2 + 1) = 3
 * 
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

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    // will not be counted as extra space
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        // get current elm, doing abs cz it might have been made negative
        const int currentNum = abs(nums[i]);
        // getting actual index of the elm
        const int actualIdx = currentNum - 1;
        // if already marked leave it, else mark
        if (nums[actualIdx] > 0)
        {
            // mark presense by making it negative
            nums[actualIdx] *= -1;
        }
    }
    // ans is all positive numbers left
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            ans.push_back(i + 1);
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