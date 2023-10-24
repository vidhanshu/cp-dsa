/**
 * @author vidhanshu borade
 * @date 24/10/2023
 *
 * Problem Statement:
 * Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 * Example 1:
 * Input: haystack = "sadbutsad", needle = "sad"
 * Output: 0
 * Explanation: "sad" occurs at index 0 and 6.
 * The first occurrence is at index 0, so we return 0.
 *
 * Example 2:
 * Input: haystack = "leetcode", needle = "leeto"
 * Output: -1
 * Explanation: "leeto" did not occur in "leetcode", so we return -1.
 *
 * Constraints:
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack and needle consist of only lowercase English characters.
 */

/**
 * Approach:
 * Approach is to use sliding window typed approach, and match character by character until it matches,
 * if whole didn't matched, then slide the window to one char ahead. and continue matching.
 * if all matched then return starting index else return -1
 *
 * TC: O(h*n)
 * SC: O(1)
 */

#include <bits/stdc++.h>

using namespace std;

int strStr(string haystack, string needle)
{
    int h = haystack.size();
    int n = needle.size();

    for (int i = 0; i <= (h - n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            // if char didn't match in current window, break
            if (haystack[i + j] != needle[j])
            {
                break;
            }
            // if at any point, j becomes n-1
            if (j == n - 1)
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    string haystack, needle;
    cin >> haystack >> haystack;

    cout << strStr(haystack, needle);
}