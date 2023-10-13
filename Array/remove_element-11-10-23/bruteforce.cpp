/**
 * @author vidhanshu borade
 * @date 11/10/2023
 *
 * Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
 * Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
 * Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
 * Return k.
 *
 * If all assertions pass, then your solution will be accepted.
 *
 * Example 1:
 * Input: nums = [3,2,2,3], val = 3
 * Output: 2, nums = [2,2,_,_]
 * Explanation: Your function should return k = 2, with the first two elements of nums being 2.
 * It does not matter what you leave beyond the returned k (hence they are underscores).
 *
 * Example 2:
 * Input: nums = [0,1,2,2,3,0,4,2], val = 2
 * Output: 5, nums = [0,1,4,0,3,_,_,_]
 * Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
 * Note that the five elements can be returned in any order.
 * It does not matter what you leave beyond the returned k (hence they are underscores).
 *
 * Constraints:
 * 0 <= nums.length <= 100
 * 0 <= nums[i] <= 50
 * 0 <= val <= 100
 */

/**
 * Approach:(self thought approach)
 * Approach is to use the two pointer approach to move all the elements which are equal to val to the 
 * end of the array
 * 
 * Time: O(2n) - n for counting counts of val & n for swaping all starting vals to end
 * Space: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // edge case if nums has 0 size
    if (!nums.size())
    {
        return 0;
    }
    // edge case if val > 50 since array itself doesn't contains 50+ numbers
    if (val > 50)
    {
        return nums.size();
    }
    // if nums is of 1 length
    if (nums.size() == 1)
    {
        return nums[0] == val ? 0 : 1;
    }

    int i = 0;
    int j = nums.size() - 1;
    int ct = count(nums.begin(), nums.end(), val);

    // skip all val from end
    while (j >= 0 && nums[j] == val)
    {
        j--;
    }

    while (i < j)
    {
        if (nums[i] == val)
        {
            // swap the current val with non val element from end
            // nums[j] will never be val
            swap(nums[i], nums[j]);
            i++;
            // skip all val from end
            while (j >= 0 && nums[j] == val)
            {
                j--;
            }
        }
        else
        {
            // skip if nums[i] not val
            i++;
        }
    }
    return nums.size() - ct;
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