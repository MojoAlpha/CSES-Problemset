#include <bits/stdc++.h>

using namespace std;

#define N 100005
#define MOD 1000000007
#define fo(i, b, n) for (long i = b; i < n; ++i)
#define rfo(i, b, n) for (long i = b; i >= n; --i)
#define all(ar) ar.begin(), ar.end()
#define rall(ar) ar.rbegin(), ar.rend()
#define mem(ar, val) memset(ar, val, sizeof(ar))
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

ll n, m, u, v, w;

void dfs(vector<vector<int>> &adj, vb &vis, long s)
{
    vis[s] = true;
    for (auto i : adj[s])
    {
        if (!vis[i])
            dfs(adj, vis, i);
    }
}

void solution()
{
    cin >> n >> m;
    vector<vector<int>> adj1(n + 1), adj2(n + 1);
    vector<tuple<ll, ll, ll>> e(m);
    fo(i, 0, m)
    {
        cin >> u >> v >> w;
        adj1[u].pb(v);
        adj2[v].pb(u);
        e[i] = {u, v, -w};
    }
    vb vis1(n + 1), vis2(n + 1);
    dfs(adj1, vis1, 1);
    dfs(adj2, vis2, n);

    vll dist(n + 1, oo);
    dist[1] = 0;
    bool flag = 0;

    fo(i, 0, n)
    {
        flag = 0;
        for (auto x : e)
        {
            tie(u, v, w) = x;
            if (vis1[u] && vis2[v] && dist[u] + w < dist[v])
            {
                flag = true;
                dist[v] = dist[u] + w;
            }
        }
    }
    if (flag)
        cout << "-1";
    else
        cout << -1 * dist[n];
}

signed main()
{
    fastIO;
    solution();
    return 0;
}