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

ll n, m, dp[1003][1030];

void solve(ll x = 0, ll y = 0, ll mask = 0, ll nxt_mask = 0)
{
    if (x == n)
        return;
    if (y >= m)
        (dp[x - 1][nxt_mask] += dp[x][mask]) %= MOD;
    else
    {
        ll my_mask = 1 << y;
        if (mask & my_mask)
            solve(x, y + 1, mask, nxt_mask);
        else
        {
            solve(x, y + 1, mask, nxt_mask | my_mask);
            if (y + 1 < m && !(mask & (my_mask << 1)))
                solve(x, y + 2, mask, nxt_mask);
        }
    }
}

signed main()
{
    fastIO;
    cin >> m >> n;
    dp[0][0] = 1;

    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < (1 << m); ++j)
            solve(i, 0, j, 0);
    }
    cout << dp[n][0];
    return 0;
}