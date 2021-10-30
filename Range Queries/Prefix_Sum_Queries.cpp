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

ll n, q, tree[8 * N][2], qr, k, x, a[2 * N];

void updation(ll id) {
    tree[id][0] = max(tree[2 * id][0], tree[2 * id][1] + tree[2 * id + 1][0]);
    tree[id][1] = tree[2 * id][1] + tree[2 * id + 1][1];
}

void build(ll id, ll lt, ll rt) {
    if(lt == rt) {
        tree[id][0] = max(a[lt], 0ll);
        tree[id][1] = a[lt];
    }
    else {
        ll mid = (lt + rt) / 2;
        build(2 * id, lt, mid);
        build(2 * id + 1, mid + 1, rt);
        updation(id);
    }
}

void update(ll id, ll lt, ll rt, ll ind, ll val) {
    if(lt == rt && lt == ind) {
        tree[id][0] = max(val, 0ll) ;
        tree[id][1] = val;
    }
    else {
        ll mid = (lt + rt) / 2;
        if(ind <= mid) update(2 * id, lt, mid, ind, val);
        else update(2 * id + 1, mid + 1, rt, ind, val);
        updation(id);
    }
}

pll query(ll id, ll lt, ll rt, ll lr, ll rr) {
    if(lr > rr) return {0, 0};
    if(lt == lr && rt == rr) return make_pair(tree[id][0], tree[id][1]);

    ll mid = (lt + rt) / 2;
    pll p1 = query(2 * id, lt, mid, lr, min(mid, rr));
    pll p2 = query(2 * id + 1, mid + 1, rt, max(mid + 1, lr), rr);
    return make_pair(max(p1.fi, p1.se + p2.fi), p1.se + p2.se);
}

void solution() {
    cin >> n >> q;
    fo(i, 1, n + 1) cin >> a[i];
    build(1, 1, n);

    while(q--) {
        cin >> qr >> k >> x;
        if(qr == 1) update(1, 1, n, k, x);
        else cout << query(1, 1, n, k, x).fi << endl;
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