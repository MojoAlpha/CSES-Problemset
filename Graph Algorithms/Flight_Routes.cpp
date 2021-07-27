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

ll n, m, k, u, v, w;

void djikstra(vector<vector<pll>> &adj, vll &dist, long s)
{
    dist[s] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        long v = pq.top().se, dv = pq.top().fi;
        pq.pop();

        if (dv != dist[v])
            continue;

        for (auto e : adj[v])
        {
            long to = e.fi, len = e.se;
            if (dist[v] + len < dist[to])
            {
                dist[to] = dist[v] + len;
                pq.push({dist[to], to});
            }
        }
    }
}

void solution()
{
    cin >> n >> m >> k;
    vector<vector<pll>> adj1(n + 1), adj2(n + 1);
    fo(i, 0, m)
    {
        cin >> u >> v >> w;
        adj1[u].pb({v, w});
        adj2[v].pb({u, w});
    }

    vll dist1(n + 1, oo), dist2(n + 1, oo);
    djikstra(adj1, dist1, 1);
    djikstra(adj2, dist2, n);

    priority_queue<ll> pq;

    fo(i, 1, n + 1)
    {
        for (auto e : adj1[i])
        {
            pq.push(dist1[i] + e.se + dist2[e.fi]);
            if (pq.size() > k)
                pq.pop();
        }
    }

    vll res(k);
    while (!pq.empty())
    {
        res[pq.size() - 1] = pq.top();
        pq.pop();
    }
    fo(i, 0, k) cout << res[i] << " ";
}

signed main()
{
    fastIO;
    solution();
    return 0;
}