/**
 * @author vidhanshu borade
 * @date 10/10/2023
 *
 * SEE THE QUESTION in file bruteforce.cpp
 *
 * Optimal:
 * - Use extra space O(n) i.e. vector<int> ans;
 * - Loop over given array, if(ar[i] == 0) then push 2 zeros to the ans other wise simply push the arr[i]
 * - do this until the size of ans becomes n
 * - copy back the ans to arr, done ✅
 * - Time: O(2n) ~ O(n)
 * - Space: O(n)
 * - Leetcode runtime: 3ms
 */

#include <bits/stdc++.h>
using namespace std;

void duplicateZeros(vector<int> &arr)
{
    // if all elements are 0
    if (all_of(arr.begin(), arr.end(), [](int a)
               { return !a; }))
    {
        return;
    }

    int n = arr.size();
    vector<int> ans;
    for (int i = 0; i < n && ans.size() <= n; i++)
    {
        // if 0 then push 2 zeros
        if (!arr[i])
        {
            ans.push_back(0);
            ans.push_back(0);
        }
        // if not push current element
        else
        {
            ans.push_back(arr[i]);
        }
    }

    // copy the ans to arr back
    for (int i = 0; i < n; i++)
    {
        arr[i] = ans[i];
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (auto &it : ar)
        cin >> it;

    duplicateZeros(ar);

    for (auto &it : ar)
        cout << it << " ";
}