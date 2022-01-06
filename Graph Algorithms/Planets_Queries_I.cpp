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
const ll sz = 2 * N;
const ll v = 32;

ll n, q, t[sz], pos[sz][v];
bool vis[sz];

void precompute(ll node) {
    deb(node);
    if(pos[node][0] > 0 || node == 0) return;

    vis[node] = 1;
    pos[node][0] = t[node];
    fo(i,1,v) {
        if(pos[pos[node][i - 1]][0] <= 0) precompute(pos[node][i - 1]);
        pos[node][i] = pos[pos[node][i - 1]][i - 1];
    }
    vis[node] = 0;
}

void solution(ll testno) {
    mem(pos, 0);
    cin >> n >> q;
    fo(i,1,n+1) cin >> t[i];
    fo(i,1,n+1)
        precompute(i);

    while(q--) {
        ll x, k;
        cin >> x >> k;
        ll ver = x;
        rfo(i,v-1,0) {
            if(k & (1ll << i))
                ver = pos[ver][i];
        }
        cout << ver << endl;
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