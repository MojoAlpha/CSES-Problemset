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

ll n, mat[6][6], res[6][6];

void matMultiply(ll a1[6][6], ll a2[6][6]) {
    ll t1[6][6];
    fo(i, 0, 6) {
        fo(j, 0, 6) {
            t1[i][j] = 0;
            fo(k, 0, 6)
                t1[i][j] = (t1[i][j] + a1[i][k] * a2[k][j]) % MOD;
        }
    }
    
    fo(i, 0, 6)
        fo(j, 0, 6)
            a1[i][j] = t1[i][j];
}

void matPow(ll n) {
    while(n) {
        if(n & 1) matMultiply(res, mat);
        matMultiply(mat, mat);
        n >>= 1;
    }
}

void solution() {
    cin >> n;
    ll val[6];
    val[0] = 1;
    fo(i, 1, 6) {
        val[i] = 0;
        fo(j, 0, i)
            val[i] += val[j];
    }
    if(n < 6) {
        cout << val[n];
        return;
    }
    matPow(n - 5);
    ll ans = 0;
    fo(i, 0, 6) ans = (ans + res[0][i] * val[5 - i]) % MOD;
    cout << ans;
}

signed main()
{
    fastIO;

    fo(i, 0, 6)
        res[i][i] = mat[0][i] = 1;
    fo(i, 1, 6)
        mat[i][i - 1] = 1;

    long t = 1;
    // cin >> t;
    while (t--)
        solution();
    return 0;
}