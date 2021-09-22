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
This problem can be broken into many simple subproblems which would help in solving current problem.
Lets say the function which gives the minimum number of coins to produce a sum of x is F(x), and the 
denominations are c1, c2, ... cn. Now lets start breaking the problem into subproblems.

F(x - c1) - minimum no. of coins for making a sum of (x - c1) & we can add one more coin to make sum x.
            Thus total no. of coins would become (1 + F(x - c1)).
F(x - c2) - minimum no. of coins for making a sum of (x - c2) & we can add one more coin to make sum x.
            Thus total no. of coins would become (1 + F(x - c2)).
... and so on.

This is the idea of a simple recursion. Now lets move on to the base terminating conditions.
CASE 1 - x < 0, this could not be achieved so the minimum no. of coins would be INFINITE (not 0).
CASE 2 - x == 0, this is our win condition, as x equals to 0 means that the sum was achieved, thus
         we return 0 in this case.

At last, we simply memoize our code to improve the time complexity.
*/

ll n, x, ci[101], memo[10 * N];

ll solve(ll v)
{
    if (v < 0)
        return oo;
    if (v == 0)
        return 0;

    if (memo[v] != -1)
        return memo[v];

    ll res = oo;
    fo(i, 0, n)
        res = min(res, solve(v - ci[i]));

    return memo[v] = 1 + res;
}

signed main()
{
    fastIO;
    mem(memo, -1);
    cin >> n >> x;
    fo(i, 0, n) cin >> ci[i];

    ll res = solve(x);
    if (res >= oo)
        cout << "-1";
    else
        cout << res;
    return 0;
}