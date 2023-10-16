/**
 * @author vidhanshu borade
 * @date 11/10/23
 */

/**
 * Approach:
 * use unordered_map to map the number to it's index
 * TC: θ(n), O(n^2)
 * SC: O(n)
 */

#define inputAr(ar)    \
    for (auto &it : ar) \
        cin >> it;

#include <bits/stdc++.h>
using namespace std;

bool checkIfExist(vector<int> &nums)
{
    unordered_map<int, int> ump;

    // mapping every number to it's index(but considering 1 based indexing instead 0)
    for (int i = 0; i < nums.size(); i++)
    {
        ump[nums[i]] = i + 1;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        // checking if the double of the elm exists
        // if exists then j will be non-zero(this was the reason behing using 1 based indexing)
        const int j = ump[2 * nums[i]];
        // question has mentioned that i should not be equal to j
        // hence checking if the idx of double elm and the elem for which double we were looking are same
        // if same then skip otherwise return true
        if (j && (j - 1 != i))
        {
            return true;
        }
    }

    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    inputAr(nums);
    cout << checkIfExist(nums);
}