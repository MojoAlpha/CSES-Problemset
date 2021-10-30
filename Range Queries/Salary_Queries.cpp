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
const ll MX = 4e5 + 4;

ll n, nn, q, u, v, bit[MX];
vll ar, br, val;
char t;

void add(ll ind, ll x) {
    for(; ind < nn; ind = (ind | (ind + 1)))
        bit[ind] += x;
}

void upd(ll ind, ll x) {
    ll id = upper_bound(all(val), ind) - val.begin() - 1;
    add(id, x);
}

ll sum(ll ind) {
    ll res = 0;
    for(; ind >= 0; ind = (ind & (ind + 1)) - 1)
        res += bit[ind];
    return res;
}

ll query(ll ind) {
    ll id = upper_bound(all(val), ind) - val.begin() - 1;
    return sum(id); 
}

void solution() {
    cin >> n >> q;
    fo(i,0,n) {
        cin >> u;
        ar.pb(u);
    }
    br = ar;
    vvll qr;
    fo(i,0,q) {
        cin >> t >> u >> v;
        qr.pb({t == '?', u, v});
        if(t == '!') br.pb(v);
    }
    sort(all(br));
    fo(i,0,br.size()) {
        if(val.empty()) val.pb(br[i]);
        else if(val.back() != br[i]) val.pb(br[i]);
    }
    nn = val.size();
    // deb(ar);
    // deb(br);
    // deb(val);

    fo(i,0,n) upd(ar[i], 1);
    for(auto &ai : qr) {
        ai[1]--;
        // deb(ai);
        if(!ai[0]) {
            upd(ar[ai[1]], -1);
            ar[ai[1]] = ai[2];
            upd(ar[ai[1]], 1);
        }
        else 
            cout << query(ai[2]) - query(ai[1]) << endl;
        
        // fo(i,0,n) cout << query(ar[i]) - query(ar[i] - 1) << " ";
        // cout << endl;
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