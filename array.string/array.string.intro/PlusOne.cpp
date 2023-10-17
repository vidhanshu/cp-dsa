/**
 * @author vidhanshu borade
 * @date 17/10/2023
 *
 * Problem:
 * You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer.
 * The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
 * Increment the large integer by one and return the resulting array of digits.
 *
 * Example 1:
 * Input: digits = [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * Incrementing by one gives 123 + 1 = 124.
 * Thus, the result should be [1,2,4].
 *
 * Example 2:
 * Input: digits = [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * Incrementing by one gives 4321 + 1 = 4322.
 * Thus, the result should be [4,3,2,2].
 *
 * Example 3:
 * Input: digits = [9]
 * Output: [1,0]
 * Explanation: The array represents the integer 9.
 * Incrementing by one gives 9 + 1 = 10.
 * Thus, the result should be [1,0].
 *
 * Constraints:
 * 1 <= digits.length <= 100
 * 0 <= digits[i] <= 9
 * digits does not contain any leading 0's.
 */

/**
 * Approach:
 * 1) Reverse the given array i.e. reverse the number
 * 2) Add one into first elm, if it is  == 10 means carry is generated, so forward carry and keep repeating the steps
 * 3) After whole process if carry is generated at end then push that carry to the nums
 * 4) Reverse the num and return
 *
 * Note: You can do this by without reversing the array also, 
 * use .insert() function which accepts 2 args, iterator to where you want to inert an elm, and what you want to insert
 * So, insert(digits.begin(), 1) would work
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

vector<int> plusOne(vector<int> &digits)
{
    // keeping carry 1 initially since 1 need to be added
    int carry = 1;
    const int N = digits.size();
    // reverse digits
    reverse(digits.begin(), digits.end());

    for (int i = 0; i < N; i++)
    {
        // [1, 2, 3, 4]
        int ans = digits[i] + carry;
        // sum is least significant digit
        int sum = (ans) % 10;
        // carry is most significant digit
        carry = (ans) / 10;
        // store the sum
        digits[i] = sum;
        // if there is no carry then there is no sense in going ahead
        if (!carry)
        {
            break;
        }
    }

    // if carry is generated from most signficant digit
    if (carry)
    {
        digits.push_back(1);
    }
    // reverse digits
    reverse(digits.begin(), digits.end());
    return digits;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    inputAr(ar);
    outputAr(plusOne(ar));
}