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

ll n, m, tree[8 * N][4], a[2 * N], k, x;

/*
0 - sum
1 - max pref
2 - max suf
3 - max subarray sum
*/

void upd(ll id) {
    tree[id][0] = tree[2 * id][0] + tree[2 * id + 1][0];
    tree[id][1] = max(tree[2 * id][1], tree[2 * id + 1][1] + tree[2 * id][0]);
    tree[id][2] = max(tree[2 * id + 1][2], tree[2 * id + 1][0] + tree[2 * id][2]);
    tree[id][3] = max({tree[2 * id][3], tree[2 * id + 1][3], tree[2 * id][2] + tree[2 * id + 1][1]});
}

void build(ll id, ll lt, ll rt) {
    if(lt == rt) {
        tree[id][0] = a[lt];
        tree[id][1] = tree[id][2] = tree[id][3] =  max(a[lt], 0ll);
    }
    else {
        ll mid = (lt + rt) / 2;
        build(2 * id, lt, mid);
        build(2 * id + 1, mid + 1, rt);
        upd(id);
    }
}

void update(ll id, ll lt, ll rt, ll ind, ll val) {
    if(lt == rt && lt == ind) {
        tree[id][0] = val;
        tree[id][1] = tree[id][2] = tree[id][3] = max(val, 0ll);
    }
    else {
        ll mid = (lt + rt) / 2;
        if(ind <= mid) update(2 * id, lt, mid, ind, val);
        else update(2 * id + 1, mid + 1, rt, ind, val);
        upd(id);
    }
}

void solution() {
    cin >> n >> m;
    fo(i, 1, n + 1) cin >> a[i];
    build(1, 1, n); 

    while(m--) {
        cin >> k >> x;
        update(1, 1, n, k, x);
        cout << max(tree[1][3], 0ll) << endl;
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