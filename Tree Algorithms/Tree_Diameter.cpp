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
#define deb2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl;
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

ll n, u, v;
vll adj[2 * N];

ll dfs(ll ver, ll par, ll &longest)
{
    ll res = 0;

    priority_queue<ll> pq;
    for (auto &ed : adj[ver])
    {
        if (ed == par)
            continue;
        ll tmp = 0;
        res = max(res, dfs(ed, ver, tmp));
        pq.push(tmp);
    }

    if (!pq.empty())
    {
        longest = 1 + pq.top();
        pq.pop();
    }
    longest = max(longest, 1ll);

    res = max(res, longest + (!pq.empty() ? pq.top() : 0ll));
    return res;
}

void solution()
{
    cin >> n;
    fo(i, 1, n)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll longest = 0;
    cout << dfs(1, -1, longest) - 1;
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