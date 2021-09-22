#include <bits/stdc++.h>

using namespace std;

#define N 100005
#define MOD 1000000007
#define fo(i, b, n) for (long i = b; i < n; ++i)
#define rfo(i, b, n) for (long i = b; i >= n; --i)
#define all(ar) ar.begin(), ar.end()
#define rall(ar) ar.rbegin(), ar.rend()
#define mem(ar, val) memset(ar, (val), sizeof(ar))
#define fi first
#define se second
#define pb push_back
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.precision(12);

typedef long long ll;
typedef pair<long, long> pll;
typedef pair<ll, ll> plll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vl> vvl;
typedef vector<vll> vvll;

const double PI = 3.141592653589793238;
const ll oo = 1e18;

/*
This problem is one of the standard questions of DP.
Before diving into DP approach, let's go through the question with a recursion approach & then we will memoize
our solution to reduce the time complexity.
Lets say the sum to construct is N, and the function that gives the number of ways to construct a sum x be F(x).
So, the problem can be initially broken into 6 parts (each part for each possible outcome on a dice roll).

F(x - 1) - Count no. of ways to construct (x - 1) & next throw could be a 1.
F(x - 2) - Count no. of ways to construct (x - 2) & next throw could be a 2.
F(x - 3) - Count no. of ways to construct (x - 3) & next throw could be a 3.
... and so on.

The value of F(x) will the aggregate of all the values for possible outcomes of the dice (1 to 6).
Next problem is the base condition for the recursion to terminate.
CASE 1 :- x < 0, we cannot construct a negative sum, thus no. of ways will be 0.
CASE 2 :- x == 0, since this is our win condition OR if the value of x becomes 0, it means that 
           a particular sum has already been achieved, thus we return 1.

Now since a decent recursion is achieved, we will just be memoizing the code, and the problem is solved.
*/

ll dp[10 * N];

ll solve(ll n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    ll res = 0;
    fo(i, 1, 7)
        res = (res + solve(n - i)) % MOD;
    return dp[n] = res;
}

signed main()
{
    fastIO;
    mem(dp, -1);
    ll n;
    cin >> n;
    cout << solve(n);
    return 0;
}