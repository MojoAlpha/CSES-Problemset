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
const ll D = 19;

int n, q, v[2 * N], sz[2 * N], dep[2 * N], tim;
int p[2 * N][D], id[2 * N], tp[2 * N], st[8 * N], a, b, qr;
vi adj[2 * N];

void update(int ind, int val, int id = 1, int lt = 1, int rt = n) {
    if(lt == rt) {
        st[id] = val;
        return;
    }
    int mid = (lt + rt) / 2;
    if(ind <= mid) update(ind, val, 2 * id, lt, mid);
    else update(ind, val, 2 * id + 1, mid + 1, rt);
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

int query(int id, int lt, int rt, int lr, int rr) {
    if(lr > rr) return 0;
    if(lt == lr && rt == rr) return st[id];
    int mid = (lt + rt) / 2;
    return max(query(2 * id, lt, mid, lr, min(rr, mid)), query(2 * id + 1, mid + 1, rt, max(mid + 1, lr), rr));
}

void dfs_sz(int src, int par) {
    sz[src] = 1;
    for(int &ed : adj[src]) {
        if(ed == par) continue;
        dep[ed] = 1 + dep[src];
        p[ed][0] = src;
        dfs_sz(ed, src);
        sz[src] += sz[ed];
    }
}

void init() {
    fo(i,1,18) {
        fo(j,1,n+1) {
            p[j][i] = p[p[j][i - 1]][i - 1];
        }
    }
}

void dfs_hld(int src, int par, int top) {
    id[src] = tim++;
    tp[src] = top;
    update(id[src], v[src]);

    int h_ed = -1, h_sz = -1;
    for(int &ed : adj[src]) {
        if(ed == par) continue;
        if(sz[ed] > h_sz) {
            h_sz = sz[ed];
            h_ed = ed;
        }
    }
    if(h_ed == -1) return;
    dfs_hld(h_ed, src, top);
    for(int &ed : adj[src]) {
        if(ed == par || ed == h_ed) continue;
        dfs_hld(ed, src, ed);
    }
}

int lca(int a, int b) {
    if(dep[a] < dep[b]) swap(a, b);
    rfo(i,D-1,0) {
        if(dep[a] - (1 << i) >= dep[b])
            a = p[a][i];
    }
    rfo(i,D-1,0) {
        if(p[a][i] != p[b][i]) {
            a = p[a][i];
            b = p[b][i];
        }
    }
    if(a != b) {
        a = p[a][0];
        b = p[b][0];
    }
    return a;
}

int path(int src, int par) {
    int res = 0;
    while(src != par) {
        if(tp[src] == src) {
            res = max(res, v[src]);
            src = p[src][0];
        }
        else if(dep[tp[src]] > dep[par]) {
            res = max(res, query(1, 1, n, id[tp[src]], id[src]));
            src = p[tp[src]][0];
        }
        else {
            res = max(res, query(1, 1, n, id[par] + 1, id[src]));
            break;
        }
    }
    return res;
}

void solution(ll testno) {
    tim = 1;
    cin >> n >> q;
    fo(i,1,n+1) cin >> v[i];
    fo(i,1,n) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs_sz(1, -1);
    init();
    dfs_hld(1, -1, 1);

    while(q--) {
        cin >> qr;
        if(qr == 1) {
            cin >> a >> b;
            v[a] = b;
            update(id[a], b);
        }
        else {
            cin >> a >> b;
            int c = lca(a, b);
            cout << max(max(path(a, c), path(b, c)), v[c]) << " ";
        }
    }
}

signed main()
{
    fastIO;
    ll test = 1;
    // cin >> test;
    fo(i, 1, test + 1)
        solution(i);
    return 0;
}