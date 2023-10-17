/**
 * @author vidhanshu borade
 * @date 17/10/2023
 */

/**
 * Approach:
 * Approach is to precompute the sums
 * we can you prefix sum approach to pre-compute the running sum then we can easily get the sum of any range in the array
 *
 * for ex:
 * Let's say array is: [1,7,3,6,5,6]
 * prefix sum array : [1,8,11,17,22,28] will make the array 1 based by storing 0 at 0th index
 * Now if want the sum of any range in the array I can easily find it using below formula:
 * sum(leftIdx, rightIdx) =  sum[rightIdx]-sum[leftIdx-1]
 * for ex:
 * sum(2, 3) = sum[3] - sum[1] = 17-8 = 9
 * 
 * but we specifically want the sum in the range 0 - (i-1) and (i+1) to (n-1)
 * So formula will become
 * leftSum = sum[i-1]
 * rightSum  = sum[n-1]-sum[i]
 * 
 * Note: will have to handle the edge cases like when i is 0 then i-1 will be -ve, similarly if i is last index you can store 0 in rightSum
 *
 * This way i can get the sum of any range within O(1) and reducing the complexity from O(n^2) to O(n)
 *
 * TC: O(n)
 * SC: O(1) - will reuse given nums array
 */

#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    const int N = nums.size();

    // pre-compute the sums
    for (int i = 1; i < N; i++)
    {
        nums[i] = nums[i - 1] + nums[i];
        cout << nums[i] << " ";
    }

    for (int i = 0; i < N; i++)
    {
        const int leftSum = ((i == 0) ? 0 : nums[i - 1]);
        const int rightSum = ((i == N - 1) ? 0 : nums[N - 1] - nums[i]);

        if (leftSum == rightSum)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (auto &it : ar)
        cin >> it;

    cout << pivotIndex(ar) << '\n';
}