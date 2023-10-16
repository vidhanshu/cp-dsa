/**
 * @author vidhanshu borade
 * @date 15/10/23
 */

/**
 * Approach:
 * Follow the "Find second largest approach" with little modification to find third largest
 * - If the array size is less than 2 then there is no third max so return max among elems
 * - Now, we will keep three pointers
 *      - largest - will store the maximum elm
 *                - initialize with max elm among first two array elms
 *      - secondLargest - will store the second maximum elm
                  - initialize with min elm among first two array elms
                  - if both elms same initialize with LONG_LONG_MIN
                  - not initializing with INT_MIN because that is in the number range(see constraints)
 *      - thirdLargest - will store the third maximum elm
 *                - this what we have to find, initialize with LONG_LONG_MIN
 * - start loop from 2 index i.e. third elm
 *      - for each i in range [2, n-1]
 *                - if nums[i] > largest then:
 *                              - since nums[i] is stricly greater than largest now we can update, secondLargest->thirdLargest, largest->secondLargest and nums[i]->largest
 *                - if nums[i] == largest then:
 *                              - this case is useless, hence ignore this case
 *                - if nums[i] < largest then:
 *                             - largest is less than nums[i] but possibly secondLargest can be greater than it, hence then this nums[i] can be secondLargest
 *                             - if nums[i] > secondLargest then:
 *                                              - secondLargest -> thirdLargest, nums[i] -> secondLargest
 *                             - if nums[i] == secondLargest then:
 *                                              - this case is useless, ignore this
 *                             - if nums[i] < secondLargest then:
 *                                              - this is possible than this nums[i] may be greater than third largest, so check and update thirdLargest accordingly.
 * Eventually just check if, thirdLargest is still LONG_LONG_MIN if yess then return max elm in the array otherwise return thirdMax
 * 
 * Reason Behind keeping thirdMax to be LONG_LONG_MIN and not INT_MIN:
 * consider the test case:
 * INT_MIN's value is -2148473648
 * [1, 2, -2148473648]
 * so in this case ans is -2148473648, but if we use INT_MIN the ans will be 2, because that's the max elm in the array
 * but since we have taken LONG_LONG_MIN here, it is working like -infinity
 * 
 * TC: O(n)   
 * SC: O(1)
 */

#define inputAr(ar)    \
    for (auto &it : ar) \
        cin >> it;
#define outputAr(ar)   \
    for (auto &it : ar) \
        cout << it << " ";
#define ll long long

#include <bits/stdc++.h>
using namespace std;

int thirdMax(vector<int> &nums)
{
    // if size 1, then first elm is ans
    if (nums.size() == 1)
    {
        return nums[0];
    }
    // if size 2, then max among two elm is ans
    if (nums.size() == 2)
    {
        return max(nums[0], nums[1]);
    }

    // will store the maximum elm in array
    int largest = max(nums[0], nums[1]);
    // will store the second maximum elm in array
    ll secondLargest = min(nums[0], nums[1]);
    if (largest == secondLargest)
    {
        secondLargest = LONG_LONG_MIN;
    }
    // will store third maximum elm in array
    ll thirdLargest = LONG_LONG_MIN;
    for (int i = 2; i < nums.size(); i++)
    {
        // if current elm is greater than largest
        if (nums[i] > largest)
        {
            // first update thirdLargest with seconLargest
            thirdLargest = secondLargest;
            // then update second largest with largest
            secondLargest = largest;
            // then update the largest to current, which is max
            largest = nums[i];
        }
        // if current elm is strictly less than largest 
        else if (nums[i] < largest)
        {
            // if current is stricly max than secondLaergest
            if (nums[i] > secondLargest)
            {
                // update third with secondLargest
                thirdLargest = secondLargest;
                // update second largest with current
                secondLargest = nums[i];
            }
            // if current is striclty less
            else if (nums[i] < secondLargest)
            {
                // if current is greater than third
                if (nums[i] > thirdLargest)
                {
                    // udpate third
                    thirdLargest = nums[i];
                }
            }
        }
    }
    // if thirdLargest is still LONG_LONG_MIN then return max elm, otherwise return thirdLargest
    return thirdLargest == LONG_LONG_MIN
               ? *max_element(nums.begin(), nums.end())
               : thirdLargest;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    inputAr(ar);
    cout << thirdMax(ar);
}