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
vll adj[N], vis(N, 0), path;
bool f;

void printPath()
{
    ll i = path.size() - 2, cnt = 1;
    while (i >= 0 && path[i] != path.back())
    {
        cnt++;
        i--;
    }
    cout << cnt + 1 << endl;
    while (i < path.size())
        cout << path[i++] << " ";
}

void dfs(ll src)
{
    if (!f)
        return;
    vis[src] = 1;
    path.pb(src);

    for (auto i : adj[src])
    {
        if (!f)
            return;
        if (vis[i] == 0)
            dfs(i);
        else if (vis[i] == 1)
        {
            f = 0;
            path.pb(i);
            printPath();
            return;
        }
    }
    if (!f)
        return;
    vis[src] = 2;
    path.pop_back();
}

signed main()
{
    fastIO;
    f = 1;
    cin >> n >> m;
    fo(i, 0, m)
    {
        cin >> a >> b;
        adj[a].pb(b);
    }

    fo(i, 1, n + 1)
    {
        if (vis[i] == 0)
        {
            dfs(i);
            if (!f)
                return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}