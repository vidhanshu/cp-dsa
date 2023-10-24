/**
 * @author vidhanshu borade
 * @date 24/10/2023
 *
 * Problem:
 * Write a function that reverses a string. The input string is given as an array of characters s.
 * You must do this by modifying the input array in-place with O(1) extra memory.
 *
 * Example 1:
 * Input: s = ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 *
 * Example 2:
 * Input: s = ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 *
 * Constraints:
 * 1 <= s.length <= 105
 * s[i] is a printable ascii character.
 */

/**
 * Approach:
 * Approach is to use two pointer approach.
 * Will keep i at 0 and j at n-1 and keep increment and decrement respectively them along with swapping, until i becomes >= j
 * 
 * TC: O(n/2)
 * SC: O(1)
 */

#define outputAr(ar)    \
    for (auto &it : ar) \
        cout << it << " ";
#include <bits/stdc++.h>

using namespace std;

void reverseString(vector<char> &s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        swap(s[i++], s[j--]);
    }
}

int main()
{
    int m;
    cin >> m;
    vector<char> s(m);

    for (int i = 0; i < m; i++)
    {
        cin >> s[i];
    }

    reverseString(s);
    outputAr(s);
}