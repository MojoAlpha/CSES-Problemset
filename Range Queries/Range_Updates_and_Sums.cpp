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
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout << fixed << setprecision(6);

typedef long long ll;
typedef long double ld;
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
const ll oo = 9e18;
const double EPS = 1e-6;
const ll sz = 2 * N;

ll n, qr, q, a, b, x, t[sz];
ll tree[4 * sz], lazy1[4 * sz], lazy2[4 * sz];

void build(ll id, ll l, ll r) {
    if(l == r) {
        tree[id] = t[l];
        return;
    }
    ll md = l + (r - l) / 2;
    build(2 * id, l, md);
    build(2 * id + 1, md + 1, r);
    tree[id] = tree[2 * id] + tree[2 * id + 1];
}

void lzupdate(ll id, ll l, ll r) {
    if(lazy2[id]) {
        ll md = l + (r - l) / 2;
        tree[2 * id] = (md - l + 1) * lazy2[id];
        tree[2 * id + 1] = (r - md) * lazy2[id];
        lazy2[2 * id] = lazy2[2 * id + 1] = lazy2[id];
        lazy1[2 * id] = lazy1[2 * id + 1] = 0;
        lazy2[id] = 0;
    }
    if(lazy1[id]) {
        ll md = l + (r - l) / 2;
        tree[2 * id] += (md - l + 1) * lazy1[id];
        tree[2 * id + 1] += (r - md) * lazy1[id];
        lazy1[2 * id] += lazy1[id];
        lazy1[2 * id + 1] += lazy1[id];
        lazy1[id] = 0;
    }
}

void update1(ll id, ll l, ll r, ll ql, ll qr, ll v) {
    // deb(id, l, r);
    if(l > r || r < ql || l > qr) return;
    if(l >= ql && r <= qr) {
        tree[id] += (r - l + 1) * v;
        lazy1[id] += v;
        return;
    }
    lzupdate(id, l, r);

    ll md = l + (r - l) / 2;
    update1(2 * id, l, md, ql, qr, v);
    update1(2 * id + 1, md + 1, r, ql, qr, v);
    tree[id] = tree[2 * id] + tree[2 * id + 1];
}

void update2(ll id, ll l, ll r, ll ql, ll qr, ll v) {
    // deb(id, l, r);
    if(l > r || r < ql || l > qr) return;
    if(l >= ql && r <= qr) {
        tree[id] = (r - l + 1) * v;
        lazy2[id] = v;
        lazy1[id] = 0;
        return;
    }
    lzupdate(id, l, r);

    ll md = l + (r - l) / 2;
    update2(2 * id, l, md, ql, qr, v);
    update2(2 * id + 1, md + 1, r, ql, qr, v);
    tree[id] = tree[2 * id] + tree[2 * id + 1];
}

ll query(ll id, ll l, ll r, ll ql, ll qr) {
    // deb(id, l, r);
    if(l > r || r < ql || l > qr) return 0;
    if(l >= ql && r <= qr) return tree[id];
    lzupdate(id, l, r);

    ll md = l + (r - l) / 2;
    return query(2 * id, l, md, ql, qr) + query(2 * id + 1, md + 1, r, ql, qr);
}

void pre() {
    fo(i,0,4*n+1) tree[i] = lazy1[i] = lazy2[i] = 0;
    build(1, 1, n);
}

void solution(int testno) {
    cin >> n >> qr;
    fo(i,1,n+1) cin >> t[i];
    pre();

    while(qr--) {
        cin >> q;
        if(q == 1) {
            cin >> a >> b >> x;
            update1(1, 1, n, a, b, x);
        }
        else if(q == 2) {
            cin >> a >> b >> x;
            update2(1, 1, n, a, b, x);
        }
        else {
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << "\n";
        }
    }
}

signed main()
{
    fastIO;
    int test = 1;

    fo(i,1,test+1)
        solution(i);
    return 0;
}