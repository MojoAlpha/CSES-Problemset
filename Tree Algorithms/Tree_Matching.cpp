#include <bits/stdc++.h>

using namespace std;

#define N 100002
#define MOD 1000000007
#define fo(i, b, n) for (long i = b; i < n; ++i)
#define rfo(i, b, n) for (long i = b; i >= n; --i)
#define all(ar) ar.begin(), ar.end()
#define rall(ar) ar.rbegin(), ar.rend()
#define mem(ar, val) memset(ar, (val), sizeof(ar))
#define fi first
#define se second
#define pb push_back
#define deb(x) cout << #x << '=' << x << endl;
#define deb2(x, y) cout << #x << '=' << x << ', ' << #y << '=' << y << endl;
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.precision(12);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

const double PI = 3.1415926535897932384626;
const ll oo = 1e18;

vll adj[2 * N];
ll dp[2 * N][2], n, u, v;

void dfs(ll vt, ll par)
{
    for (auto &to : adj[vt])
    {
        if (to == par)
            continue;
        dfs(to, vt);
        dp[vt][0] += max(dp[to][0], dp[to][1]);
    }

    for (auto &to : adj[vt])
    {
        if (to == par)
            continue;
        //                              1      2     3                    4
        dp[vt][1] = max(dp[vt][1], dp[to][0] + 1 + dp[vt][0] - max(dp[to][0], dp[to][1]));
    }
}

/*
1 - maximum set with to as root without selecting any child of to
2 - the extra added edge into set
3 - the maximum set without selecting any child of vt
4 - the value which was added to [3] while calculating [3]
*/

void solution()
{
    cin >> n;
    fo(i, 1, n)
    {
        cin >> u >> v;
        adj[u - 1].pb(v - 1);
        adj[v - 1].pb(u - 1);
    }
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]);
}

signed main()
{
    fastIO;
    long t = 1;
    // cin >> t;
    while (t--)
        solution();
    return 0;
}