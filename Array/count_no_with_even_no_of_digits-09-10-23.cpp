/**
 * @author vidhanshu borade
 * @date 09/10/2023
 *
 * Problem:
 * Given an array nums of integers, return how many of them contain an even number of digits.
 *
 * Example 1:
 * Input: nums = [12,345,2,6,7896]
 * Output: 2
 *
 * Explanation:
 * 12 contains 2 digits (even number of digits).
 * 345 contains 3 digits (odd number of digits).
 * 2 contains 1 digit (odd number of digits).
 * 6 contains 1 digit (odd number of digits).
 * 7896 contains 4 digits (even number of digits).
 * Therefore only 12 and 7896 contain an even number of digits.
 *
 * Example 2:
 * Input: nums = [555,901,482,1771]
 * Output: 1
 *
 * Explanation:
 * Only 1771 contains an even number of digits.
 *
 * Constraints:
 * 1 <= nums.length <= 500
 * 1 <= nums[i] <= 105
 */

/**
 * Approach:
 * We can find the count of number of digits in the number using % operator:
 * if let's say we have a number n so to get it's last digit we can mod it with 10, similarly if we want to remove the last digit
 * we can divide it by 10
 * Ex: n = 123
 * last_digit = 123 % 10 = 3
 * number_after_removing_last_digit = 123 / 10 = 12
 *
 * Now, simply get the number of digit count in the number and check if it is even or not
 */

#include <bits/stdc++.h>
using namespace std;

int getDigCount(int n)
{
    int ct = 0;
    while (n)
    {
        n /= 10;
        ct++;
    }
    return ct;
}
int findNumbers(vector<int> &ar)
{
    int ct = 0;
    for (auto &it : ar)
    {
        if (!(getDigCount(it) & 1))
        {
            ct++;
        }
    }
    return ct;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (auto &it : ar)
        cin >> it;

    cout << findNumbers(ar) << '\n';
}