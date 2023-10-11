/**
 * @author vidhanshu borade
 * @date 11/10/2023
 *
 * Problem:
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 * The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
 *
 * Example 1:
 * Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * Output: [1,2,2,3,5,6]
 * Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
 * The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
 *
 * Example 2:
 * Input: nums1 = [1], m = 1, nums2 = [], n = 0
 * Output: [1]
 * Explanation: The arrays we are merging are [1] and [].
 * The result of the merge is [1].
 *
 * Example 3:
 * Input: nums1 = [0], m = 0, nums2 = [1], n = 1
 * Output: [1]
 * Explanation: The arrays we are merging are [] and [1].
 * The result of the merge is [1].
 * Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 *
 * Constraints:
 * nums1.length == m + n
 * nums2.length == n
 * 0 <= m, n <= 200
 * 1 <= m + n <= 200
 * -10^9 <= nums1[i], nums2[j] <= 10^9
 *
 * Follow up: Can you come up with an algorithm that runs in O(m + n) time?
 */

/**
 * Approach: (Self thought approach)
 * Copy the nums1 m elements into a temporary array and then use merge sort approach to merge these two sorted arrays
 *
 * Time: O(2m+n)
 * Space: O(m)
 * Leetcode runtime: 3ms
 */

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> temp(m);
    for (int i = 0; i < m; i++)
        temp[i] = nums1[i];

    int left_it = 0, right_it = 0, i = 0;

    // merge the arrays into nums1
    while (left_it < m && right_it < n)
    {
        if (temp[left_it] < nums2[right_it])
        {
            nums1[i++] = temp[left_it++];
        }
        else
        {
            nums1[i++] = nums2[right_it++];
        }
    }
    // leftover elements in the temp
    while (left_it < m)
    {
        nums1[i++] = temp[left_it++];
    }
    // leftover elements in the nums2
    while (right_it < n)
    {
        nums1[i++] = nums2[right_it++];
    }
}
int main()
{
    int m;
    cin >> m;
    int n;
    cin >> n;
    vector<int> nums1(m + n);
    vector<int> nums2(n);

    for (auto &it : nums1)
        cin >> it;
    for (auto &it : nums2)
        cin >> it;

    merge(nums1, m, nums2, n);
}