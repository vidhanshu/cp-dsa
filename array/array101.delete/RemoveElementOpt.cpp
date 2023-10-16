/**
 * @author vidhanshu borade
 * @date 11/10/2023
 */

/**
 * Approach: (used hint #3)
 * Approach is to ignore the elements whose value is equal to val and keep filling the only those elements
 * which are not equal to val
 *
 * i = 0
 * we will iterate over array once and for each element will check
 * if element != val then will keep the element storing in the array itself and increment i by 1
 *
 * eventually the i will represent what will be the size of resultant array
 *
 * Time: O(n)
 * Space: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    // not required, but just for optimization purpose
    if (val > 50)
    {
        return nums.size();
    }

    int i = 0;
    // iterate over an array
    for (auto &it : nums)
    {
        // iff current elem is not val
        if (it != val)
        {
            nums[i++] = it;
        }
    }
    // i represents the value of ultimately k
    return i;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (auto &it : ar)
        cin >> it;

    cout << removeElement(ar, n) << '\n';
}