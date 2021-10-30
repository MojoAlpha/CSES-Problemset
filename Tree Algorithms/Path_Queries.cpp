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

ll n, q, v[2 * N], ar[4 * N], bit[4 * N], a, b, s, x, qr, tim;
vll adj[2 * N], ind[4 * N];

void dfs(ll src, ll par) {
    ind[src].pb(tim);
    ar[tim++] = src;
    for(ll &ed : adj[src]) {
        if(ed == par) continue;
        dfs(ed, src);
    }
    ind[src].pb(tim);
    ar[tim++] = src;
}

void add(ll id, ll val) {
    for(; id < 2 * n; id = id | (id + 1))
        bit[id] += val;
}

ll sum(ll id) {
    ll res = 0;
    if(id < 0) return res;
    for(; id >= 0; id = (id & (id + 1)) - 1)
        res += bit[id];
    return res;
}

void solution(ll testno) {
    tim = 0;
    cin >> n >> q;
    fo(i,0,n) cin >> v[i];
    fo(i,1,n) {
        cin >> a >> b;
        adj[a - 1].pb(b - 1);
        adj[b - 1].pb(a - 1);
    }
    dfs(0, -1);
    fo(i,0,n) {
        add(ind[i][0], v[i]);
        add(ind[i][1], -v[i]);
    }

    while(q--) {
        cin >> qr;
        if(qr == 1) {
            cin >> s >> x;
            s--;
            add(ind[s][0], x - v[s]);
            add(ind[s][1], -x + v[s]);
            v[s] = x;
        }
        else {
            cin >> s;
            s--;
            cout << sum(ind[s][0]) << endl;
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