/**
 * @author vidhanshu borade
 * @date 11/10/23
 */

/**
 * Approach:
 * use unordered_map to map the number to it's index
 * TC: θ(n) -> O(n^2)
 * SC: O(n)
 * BEATS: 90% c++ users timewise
 */

#define input_ar(ar)    \
    for (auto &it : ar) \
        cin >> it;
#define output_ar(ar)   \
    for (auto &it : ar) \
        cout << it << " ";

#include <bits/stdc++.h>
using namespace std;

bool checkIfExist(vector<int> &arr)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<int, int> ump;

    for (int i = 0; i < arr.size(); i++)
    {
        ump[arr[i]] = i + 1;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        const int idx = ump[2 * arr[i]];
        if (idx && (idx - 1 != i))
        {
            return true;
        }
    }

    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    input_ar(ar);
    cout << checkIfExist(ar);
}