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

ll n, q, u, v, l, timer;
vll adj[2 * N], tin, tout;
vvll up;

void dfs(ll ver, ll par) {
    tin[ver] = ++timer;
    up[ver][0] = par;

    fo(i, 1, l + 1) {
        if(up[ver][i - 1] != -1)
            up[ver][i] = up[up[ver][i - 1]][i - 1];
    }

    for(auto &ed : adj[ver]) {
        if(ed == par) continue;
        dfs(ed, ver);
    }

    tout[ver] = ++timer;
}

void preprocess() {
    timer = 0;
    l = floor(log2(n)) + 1;
    up.assign(n + 1, vll(l + 1, -1));
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);
    dfs(1, -1);
}

ll find_ancestor(ll node, ll k) {
    if(k == 0) return node;
    if(node == -1) return -1;
    ll cc = 0, pw = 1;
    while(pw <= k) {
        pw *= 2;
        cc++;
    }
    pw /= 2;
    cc--;
    return find_ancestor(up[node][cc], k - pw);
}

void solution() {
    cin >> n >> q;
    fo(i,2,n+1) {
        cin >> v;
        adj[v].pb(i);
    }
    preprocess();

    while(q--) {
        cin >> u >> v;
        cout << find_ancestor(u, v) << endl;
    }
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