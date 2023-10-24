/**
 * @author vidhanshu borade
 * @date 22/10/2023
 */

/**
 * Approach: (Approach from discussion section)
 * 
 * - We start at the right end of each binary number, adding the digits and any carry-over value, and storing the result in a new string.
 * - Now we move to the next digit on the left and repeats the process until it has gone through all the digits in both binary numbers.
 * - If there is any carry-over value after adding all the digits, append it to the end of the new string.
 * - Finally, the new string is reversed and returned as the sum of the two binary numbers.
 *
 * TC: O(n)
 * SC: O(n) - to store the ans
 */

#define outputAr(ar)    \
    for (auto &it : ar) \
        cout << it << " ";

#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b)
{
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        if (i >= 0)
            carry += a[i--] - '0';
        if (j >= 0)
            carry += b[j--] - '0';
        ans += carry % 2 + '0';
        carry /= 2;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << addBinary(s1, s2);
}