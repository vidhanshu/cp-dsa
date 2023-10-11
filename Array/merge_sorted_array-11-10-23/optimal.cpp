/**
 * @author vidhanshu borade
 * @date 11/10/2023
 *
 * Approach: (Took reference from discussion section)
 * Approach is to go from end to start instead of start to end, it means that in previous
 * approach we were starting our left right pointers from
 * 0 and going towards n-1, this way we need extra space to solve the problem.
 * What we will do is, we will initialize 3 iterators(variables)
 * left_it = m - 1      // iterates over first array from m - 1 to 0
 * right_it = n - 1      // iterates over second array from n - 1 to 0
 * i = m + n - 1  // index representing for which place we are finding the number
 * 
 * and instead of going from start to end we will go from end to start which means now
 * we will be iterating over sorted arrays in decreasing order and not in increasing.
 *
 * So we will look for the largest element instead of smallest since the array is being filled
 * from end to start
 *
 * while left_it >= 0 and right_it >= 0:
 *      check if nums1[left_it] > nums2[right_it] then nums1[i--] = nums1[left_it--]; // store the largest element and decrease i and left_it
 *      else nums1[i--] = nums2[right_it--];
 * handle leftover elements
 *
 * this way array will get filled form end to start i.e. from largest element to smallest one
 *
 * Time: O(m+n)
 * Space: O(1)
 * Leetcode runtime: 0ms
 * Beasts 100% of c++ users solutions timewise
 */

#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> nums1, int m, vector<int> nums2, int n)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int left_it = m - 1;
    int right_it = n - 1;
    int i = m + n - 1;

    while (left_it >= 0 && right_it >= 0)
    {
        if (nums1[left_it] > nums2[right_it])
        {
            nums1[i--] = nums1[left_it--];
        }
        else
        {
            nums1[i--] = nums2[right_it--];
        }
    }
    while (left_it >= 0 && i >= 0)
    {
        nums1[i--] = nums1[left_it--];
    }
    while (right_it >= 0 && i >= 0)
    {
        nums1[i--] = nums2[right_it--];
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