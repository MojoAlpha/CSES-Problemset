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

ll n, m, a, b;
vll adj[sz];

void solution(ll testno) {
    cin >> n >> m;
    vll deg(n + 1, 0), dp(n + 1, 0);
    fo(i,0,m) {
        cin >> a >> b;
        adj[a].pb(b);
        deg[b]++;
    }

    queue<ll> q;
    fo(i,1,n+1) {
        if(deg[i] == 0) {
            q.push(i);
            if(i == 1)
                dp[i] = 1;
        }
    }

    while(!q.empty()) {
        ll p = q.front();
        q.pop();

        for(auto &ed : adj[p]) {
            dp[ed] += dp[p];
            dp[ed] %= MOD;
            deg[ed]--;
            if(deg[ed] == 0) {
                q.push(ed);
                if(ed == 1)
                    dp[ed] = 1;
            }
        }
    }
    cout << dp[n];
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