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
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(12);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '"' << x << '"';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]" << endl;}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif

const double PI = 3.1415926535897932384626;
const ll oo = 1e18;

int n, l, q, u, v, timer, tin[2 * N], tout[2 * N], pdist[40];
vi adj[2 * N], up[2 * N];

void dfs(int src, int par) {
    tin[src] = ++timer;
    up[src][0] = par;
    fo(i, 1, l + 1)
        up[src][i] = up[up[src][i - 1]][i - 1];

    for(int &ed : adj[src]) {
        if(ed == par) continue;
        dfs(ed, src);
    }

    tout[src] = ++timer;
}

bool isAncestor(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
    if(isAncestor(u, v)) return u;
    if(isAncestor(v, u)) return v;

    rfo(i, l, 0) {
        if(!isAncestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int lca_dist(int lca_val, int u) {
    int dist = 0;
    if(lca_val == u) return dist;

    rfo(i, l, 0) {
        if(!isAncestor(up[u][i], lca_val)) {
            u = up[u][i];
            dist += pdist[i];
        }
    }
    return dist + 1;
}

void solution() {
    timer = 0;
    cin >> n >> q;
    l = floor(log2(n)) + 1;
    fo(i,1,n + 1)
        up[i].resize(l + 1, 1);

    fo(i, 1, n) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 1);

    while(q--) {
        cin >> u >> v;
        ll t1 = lca(u, v);
        printf("%d\n", lca_dist(t1, u) + lca_dist(t1, v));
    }
}

signed main()
{
    fastIO;
    pdist[0] = 1;
    fo(i,1,40) pdist[i] = (pdist[i - 1] * 2);
    long t = 1;
    while (t--)
        solution();
    return 0;
}