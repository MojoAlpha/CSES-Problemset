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

ll n, m, a, b;
vll adj[N], comb(N, 0);

void bfs(ll src)
{
    queue<ll> q;
    vi vis(n + 1, 0);
    q.push(src);
    vis[src];
    comb[1] = 1;

    while (!q.empty())
    {
        ll p = q.front();
        q.pop();

        for (auto ed : adj[p])
        {
            if (vis[ed] != 2)
            {
                comb[ed] = (comb[ed] + comb[p]) % MOD;
                if (vis[ed] == 0)
                    q.push(ed);
            }
        }
        vis[p] = 2;
    }
}

signed main()
{
    fastIO;
    cin >> n >> m;
    fo(i, 0, m)
    {
        cin >> a >> b;
        adj[a].pb(b);
    }
    bfs(1);
    cout << comb[n];
    return 0;
}