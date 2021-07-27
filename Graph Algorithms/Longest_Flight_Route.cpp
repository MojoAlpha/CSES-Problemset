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

ll n, m, a, b, dist[N], par[N];
vll adj[N];

void djikstra(ll src)
{
    dist[src] = 0;
    priority_queue<plll, vector<plll>, greater<plll>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();

        if (dist[p.se] != p.fi)
            continue;

        for (auto edge : adj[p.second])
        {
            if (dist[edge] > p.fi - 1)
            {
                dist[edge] = p.fi - 1;
                par[edge] = p.se;
                pq.push({dist[edge], edge});
            }
        }
    }
}

int main()
{
    fastIO;

    fo(i, 0, N)
    {
        par[i] = -1;
        dist[i] = 1;
    }

    cin >> n >> m;
    fo(i, 0, m)
    {
        cin >> a >> b;
        adj[a].pb(b);
    }
    djikstra(1);

    if (dist[n] >= 0)
    {
        printf("IMPOSSIBLE");
        return 0;
    }

    ll i = n;
    vll path;

    while (par[i] != -1)
    {
        path.pb(i);
        i = par[i];
    }
    path.pb(i);
    cout << path.size() << endl;
    reverse(all(path));
    for (auto i : path)
        printf("%lld ", i);
    return 0;
}