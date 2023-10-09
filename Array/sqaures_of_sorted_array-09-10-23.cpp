/**
 * @author vidhanshu borade
 * @date 09/10/2023
 *
 * Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
 *
 * Example 1:
 * Input: nums = [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * Explanation: After squaring, the array becomes [16,1,0,9,100].
 * After sorting, it becomes [0,1,9,16,100].
 *
 * Example 2:
 * Input: nums = [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 *
 * Constraints:
 * 1 <= nums.length <= 104
 * -104 <= nums[i] <= 104
 * nums is sorted in non-decreasing order.
 *
 * Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
 */

/**
 * Approach:
 *
 * 1) Bruteforce: sqaure the array sort the array - TC -> O(n.logn)
 * 2) Optimized: Two pointer approach:
 *    Let's assume the array to be completely positive array
 *    ex: [-4,-1,0,3,10] -> [4,1,0,3,10]  so here we can observe that array is first decreasing then increaseing
 *    so we can take advantage of this fact and find a point where it is neutral i.e. common point of increasing and decreasing arrays and then can use merge sort appraoch two merge two sorted arrays
 *
 *    Algorithm:
 *    loop over an array and find a point where abs(ar[i]) < abs(ar[i + 1])
 *    Now,
 *    from i to 0 is your first array which is sorted in increasinng order
 *    from i + 1 to n -1 your second array which is sorted in increaseing order
 *    use merge function two merge two sorted arrays also sqaure elements on the go
 *
 *    Complexity:
 *    Time = O(3n) ~ O(n)
 *    Space = O(n)
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int> &ar)
{
    // corner case
    if (ar.size() == 1)
    {
        return {ar[0] * ar[0]};
    }
    const int n = ar.size();
    vector<int> ans(n);

    int common_point = -1;

    // find the common point
    for (int i = 0; i < n - 1; i++)
    {
        if (abs(ar[i]) < abs(ar[i + 1]))
        {
            common_point = i;
            break;
        }
    }

    // this case will be there  if, array is in decreasing order of negative numbers
    // ex: -4 -3 -2 -1 0
    if (common_point == -1)
    {
        for (int i = 0; i < n; i++)
        {
            ans[n - i - 1] = ar[i] * ar[i];
        }
        return ans;
    }

    // simply merging two sorted arrays
    int left_it = common_point, right_it = common_point + 1, i = 0;

    while (left_it >= 0 && right_it < n)
    {
        if (abs(ar[left_it]) < abs(ar[right_it]))
        {
            ans[i++] = ar[left_it] * ar[left_it--];
        }
        else
        {
            ans[i++] = ar[right_it] * ar[right_it++];
        }
    }

    // if elements are left over in any of the array
    while (left_it >= 0)
    {
        ans[i++] = ar[left_it] * ar[left_it--];
    }
    while (right_it < n)
    {
        ans[i++] = ar[right_it] * ar[right_it++];
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (auto &it : ar)
        cin >> it;

    for (auto it : sortedSquares(ar))
    {
        cout << it << " ";
    }
}