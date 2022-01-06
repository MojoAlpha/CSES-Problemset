#include <bits/stdc++.h>

using namespace std;

#define N 100002
#define MOD 1000000007
#define MOD2 998244353
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

ll n, m, a, b, c;
vector<pll> adj[N];

void solution(ll testno) {
    cin >> n >> m;
    fo(i,0,m) {
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }

    vvll dp(n + 1, vll({oo, 0ll, oo, 0ll}));
    vb vis(n + 1, 0);
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});

    while(!pq.empty()) {
        pll p = pq.top();
        pq.pop();
        if(vis[p.se]) continue;
        vis[p.se] = 1;

        for(auto &ed : adj[p.se]) {
            ll wt = ed.se, to = ed.fi;
            if(vis[to]) continue;

            if(p.fi + wt < dp[to][0]) {
                dp[to][0] = p.fi + wt;
                dp[to][1] = dp[p.se][1];
                dp[to][2] = dp[p.se][2] + 1;
                dp[to][3] = dp[p.se][3] + 1;
                pq.push({dp[to][0], to});
            }
            else if(p.fi + wt == dp[to][0]) {
                dp[to][1] += dp[p.se][1];
                dp[to][1] %= MOD;
                dp[to][2] = min(dp[to][2], dp[p.se][2] + 1);
                dp[to][3] = max(dp[to][3], dp[p.se][3] + 1);
                pq.push({dp[to][0], to});
            }
        }
    }
    fo(i,0,4) cout << dp[n][i] << " ";
}

signed main()
{
    fastIO;
    ll test = 1;
    // cin >> test;
    fo(i, 1, test + 1) {
        solution(i);
        cout << endl;
    }
    return 0;
}