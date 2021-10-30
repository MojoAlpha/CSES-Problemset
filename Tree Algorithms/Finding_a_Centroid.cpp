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
const ll mn = 2 * N;

ll n, a, b, cnt[mn], centroid;
vll adj[mn];

void dfs_cnt(ll ver, ll par) {
    cnt[ver] = 1;
    for(auto &ed : adj[ver]) {
        if(ed == par) continue;
        dfs_cnt(ed, ver);
        cnt[ver] += cnt[ed];
    }
}

void dfs_centroid(ll ver, ll par) {
    bool isCentroid = 1;
    for(auto &ed : adj[ver]) {
        if(ed == par) continue;
        if(cnt[ed] > n / 2)
            isCentroid = 0;
    }
    if(n - cnt[ver] > n / 2)
        isCentroid = 0;
    if(isCentroid)
        centroid = ver;
    
    for(auto &ed : adj[ver]) {
        if(ed == par) continue;
        dfs_centroid(ed, ver);
    }
}

void solution(ll testno) {
    cin >> n;
    fo(i,1,n) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs_cnt(1, -1);
    dfs_centroid(1, -1);
    cout << centroid;
}

signed main()
{
    fastIO;
    centroid = 0;
    ll test = 1;
    // cin >> test;
    fo(i, 1, test + 1)
        solution(i);
    return 0;
}