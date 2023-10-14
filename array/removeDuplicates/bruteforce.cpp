/**
 * @author vidhanshu borade
 * @date 11/10/23
 *
 * Problem description:
 * Given an integer array nums sorted in non-decreasing order, remove the duplicates
 * in-place such that each unique element appears only once. The relative order of
 * the elements should be kept the same. Then return the number of unique elements in nums.
 * Consider the number of unique elements of nums to be k, to get accepted, you need
 * to do the following things:
 * Change the array nums such that the first k elements of nums contain the unique elements
 * in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
 * Return k.

 * If all assertions pass, then your solution will be accepted.
*/

/**
 * Approach:
 * Use set's property which is, you get unique as well as sorted elements
 * 
 * TC: O(n.logn)
 * SC: ~ O(n)
 */

#define inputAr(ar)    \
    for (auto &it : ar) \
        cin >> it;
#define outputAr(ar)   \
    for (auto &it : ar) \
        cout << it << " ";

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    set<int> st(nums.begin(), nums.end());
    int i = 0;
    for (auto &it : st)
    {
        nums[i++] = it;
    }
    return i;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    inputAr(ar);
    outputAr(ar);
}