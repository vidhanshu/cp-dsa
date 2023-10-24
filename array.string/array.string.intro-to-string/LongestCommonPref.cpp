/**
 * @author vidhanshu borade
 * @date 24/10/2023
 *
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 *
 * Example 2:
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 * Constraints:
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lowercase English letters.
 */

/**
 * Approach:
 * Approach, is naive approach.
 * - To match all ith chars in strings and check if all they are equal if they all are equal push them into ans
 * - if any ith char is not same in all just stop and return ans unitl now
 *
 * TC: O(m*n)
 * SC: O(1)
 */

#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int m = 200;
    string ans;
    const int N = strs.size();

    // Get the min length among all strings 
    for (int i = 0; i < N; i++)
    {
        m = m < strs[i].size() ? m : int(strs[i].size());
    }

    // i refer, ith character
    for (int i = 0; i < m; i++)
    {
        // check if ith char in all strings are same or not
        bool allMatched = true;

        for (int j = 1; j < N; j++)
        {
            if (strs[j - 1][i] != strs[j][i])
            {
                allMatched = false;
                break;
            }
        }

        // if all matched, then push it to ans
        if (allMatched)
        {
            ans.push_back(strs[0][i]);
        }
        // if ith char is not same in all, just return ans until now
        else
        {
            return ans;
        }
    }
    return ans;
}

int main()
{
    int m;
    cin >> m;
    vector<string> strs(m);
    for (int i = 0; i < m; i++)
    {
        cin >> strs[i];
    }
    cout << longestCommonPrefix(strs);
}