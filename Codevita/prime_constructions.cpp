/**
 * @author vidhanshu borade
 * @date 14/10/23
*/

/**
 * Problem Description
 * A math game is introduced in a school competition to test the skills of students. The game deals with 
 * Prime numbers.
 * The game rules are as follows:
 * •	From the given set of distinct natural numbers as input, consider the smallest natural number as q.
 * •	Your task is to compute the smallest prime number (p) such that when p is divided by all the distinct 
 *      numbers in the input, except q, should result q as the remainder.
 * 
 * Constraints
 * 1 < n < 11
 * p < 10 ^ 10
 * 
 * Input
 * Input consists of n+1 number of distinct natural numbers separated by spaces.
 * Output
 * Print single integer p if such a p exists, else print "None".
 * 
 * Time Limit (secs)
 * 1
 * Examples
 * Input
 * 3 4 5 1
 * Output
 * 61
 * 
 * Explanation
 * Here the n+1 numbers are 3, 4, 5 and 1 where q=1 (the least of the numbers)
 * The smallest number that leaves remainder 1 when divided by 3, 4 and 5 is 61 and is prime. Hence, 
 * output is 61.
 * 
 * Example 2
 * Input
 * 3 4 5 2
 * Output
 * None
 * 
 * Explanation
 * Here q=2. Any number that when divided by 4 leaving remainder 2 must be an even number e.g., 6, 10, 14 
 * etc. Hence it can't be prime. Hence, output is "None"
 * 
 * TC: ~ O(log(10^10) * sqrt(actual_ans + q))
*/

#define ll long long
#include <bits/stdc++.h>
using namespace std;

// to check if num is prime
// can also use normal approach, but this is much optimal
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    // skip all multiples of 6
    for (ll i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// to compute lcm
// gcd * lcm = a * b
ll __lcm(int a, int b)
{
    return (a * 1ll * b) / __gcd(a, b);
}

int main()
{
    vector<ll> arr;
    ll q = LLONG_MAX;
    ll num;

    // input numbers
    while (cin >> num)
    {
        arr.push_back(num);
        if (num < q)
            q = num;
    }

    // find min idx
    int min_idx = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == q)
            min_idx = i;
    }

    // swap smallest elm to end
    swap(arr[n - 1], arr[min_idx]);

    // find lcm of all except smallest
    ll ans = 1;
    for (int i = 0; i < n - 1; i++)
    {
        ans = __lcm(ans, arr[i]);
    }

    ll actual_ans = ans;
    const ll power = 1e10;
    while (actual_ans <= power)
    {
        if (isPrime(actual_ans + q))
        {
            cout << actual_ans + q;
            return 0;
        }
        /**
         * Multiplying the lcm by 2 to keep lcm, common multiple of 
         * all distintc natural numbers in the array except smallest one i.e. q
        */
        actual_ans = 2 * actual_ans;
    }
    // if no such prime exists print None
    cout << "None";
    return 0;
}