/**
 * @author vidhanshu borade
 * @date 22/10/2023
 *
 * Problem:
 *
 * Given two binary strings a and b, return their sum as a binary string.
 *
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 *
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 * Constraints:
 * 1 <= a.length, b.length <= 104
 * a and b consist only of '0' or '1' characters.
 * Each string does not contain leading zeros except for the zero itself.
 */

/**
 * Approach:
 * This is basic addition but with lot of cases to be handled,
 * The approach is to handle each case manually
 * 1 + 1 (with carry, without carry)
 * 1 + 0 / 0 + 1 (with carry, without carry)
 * 0 + 0 (with carry, without carry)
 * different lengths of a and b
 * 
 * TC: O(n)
 * SC: O(n) - to store ans
 */

#define outputAr(ar)    \
    for (auto &it : ar) \
        cout << it << " ";

#include <bits/stdc++.h>
using namespace std;

void addBins(string &a, string &b, string &ans, bool &carry, int &i)
{
    // NOTE: in this function a's length will be >= b

    int m, n;
    m = a.size(), n = b.size();

    // if i has passed b's length
    if (i < n)
    {
        // if 1 + 1
        if (a[i] == '1' && b[i] == '1')
        {
            // with carry i.e. 1+1+1
            if (carry)
            {
                ans.push_back('1');
            }
            // without carry
            else
            {
                ans.push_back('0');
            }
            // for sure carry will be generated
            carry = true;
        }
        // if 1 + 0 or 0 + 1
        else if (a[i] == '1' && b[i] == '0' || a[i] == '0' && b[i] == '1')
        {
            // with carry i.e. 1 + 0 + 1 or 0 + 1 + 1
            if (carry)
            {
                ans.push_back('0');
            }
            // without carry
            else
            {
                ans.push_back('1');
            }
        }
        // if 0 + 0
        else if (a[i] == '0' && b[i] == '0')
        {
            // with carry i.e. 0 + 0 + 1
            if (carry)
            {
                ans.push_back('1');
                carry = false;
            }
            // without carry
            else
            {
                ans.push_back('0');
            }
        }
    }
    // else keep pushing the elm's of a, also take care if carry was there
    else
    {
        // if current elem is 1
        if (a[i] == '1')
        {
            // also carry exists
            if (carry)
            {
                ans.push_back('0');
            }
            else
            {
                ans.push_back('1');
            }
        }
        // if current elm is 0
        else
        {
            // if carry exists from previois addition
            if (carry)
            {
                // push 1
                ans.push_back('1');
                // and reset carry, since there is no generation of carry from this addition
                carry = false;
            }
            else
            {
                ans.push_back('0');
            }
        }
    }
}

string addBinary(string a, string b)
{
    // reversing will made it easy to add
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string ans;

    int m, n;
    m = a.size(), n = b.size();
    int i = 0;
    bool carry = false;
    while (i < max(m, n))
    {
        // making sure length of first arg will always be >= second arg
        addBins(m >= n ? a : b, n <= m ? b : a, ans, carry, i);
        i++;
    }

    // if after everything, still there is carry push 1
    if (carry)
    {
        ans.push_back('1');
    }

    // reverse the ans, to get actual ans
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << addBinary(s1, s2);
}