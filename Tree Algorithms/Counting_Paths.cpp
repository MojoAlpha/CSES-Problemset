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

ll n, m, u, v, l, timer, tin[2 * N], tout[2 * N], val[2 * N];
vll adj[2 * N], up[2 * N];

void dfs1(ll ver, ll par) {
    tin[ver] = ++timer;
    up[ver][0] = par;
    fo(i, 1, l + 1)
        up[ver][i] = up[up[ver][i - 1]][i - 1];
    
    for(auto &ed : adj[ver]) {
        if(ed == par) continue;
        dfs1(ed, ver);
    }

    tout[ver] = ++timer;
}

void dfs2(ll ver, ll par) {
    for(auto &ed : adj[ver]) {
        if(ed == par) continue;
        dfs2(ed, ver);
        val[ver] += val[ed];
    }
}

bool isAncestor(ll u, ll v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

ll lca(ll u, ll v) {
    if(isAncestor(u, v)) return u;
    if(isAncestor(v, u)) return v;

    rfo(i, l, 0) {
        if(!isAncestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void solution() {
    timer = 0;
    cin >> n >> m;
    l = floor(log2(n)) + 1;
    fo(i, 0, n + 1) up[i].resize(l + 1, 1);

    fo(i, 1, n) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(1, 1);
    
    vvll qrs;
    while(m--) {
        cin >> u >> v;
        ll tt = lca(u, v);
        val[u]++;
        val[v]++;
        val[tt] -= 2;
        qrs.pb({u, v, tt});
    }
    
    dfs2(1, 1);
    fo(i, 0, qrs.size())
        val[qrs[i][2]]++;
    fo(i,1,n+1) cout << val[i] << " ";
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