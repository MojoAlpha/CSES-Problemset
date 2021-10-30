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

ll n, m, q, tree[8 * N], a[2 * N];

void updation(ll id) {
    tree[id] = max(tree[2 * id], tree[2 * id + 1]);
}

void build(ll id, ll lt, ll rt) {
    if(lt == rt)
        tree[id] = a[lt];
    else {
        ll mid = (lt + rt) / 2;
        build(2 * id, lt, mid);
        build(2 * id + 1, mid + 1, rt);
        updation(id);
    }
}

void update(ll id, ll lt, ll rt, ll ind, ll val) {
    if(lt == rt && lt == ind)
        tree[id] = val;
    else {
        ll mid = (lt + rt) / 2;
        if(ind <= mid) update(2 * id, lt, mid, ind, val);
        else update(2 * id + 1, mid + 1, rt, ind, val);
        updation(id);
    }
}

ll query(ll id, ll lt, ll rt, ll val) {
    if(tree[id] < val) return 0;
    if(lt == rt) return lt;
    ll mid = (lt + rt) / 2;

    if(tree[2 * id] >= val) return query(2 * id, lt, mid, val);
    else return query(2 * id + 1, mid + 1, rt, val);
}

void solution() {
    cin >> n >> m;
    fo(i, 1, n + 1) cin >> a[i];
    build(1, 1, n);

    while(m--) {
        cin >> q;
        ll ans = query(1, 1, n, q);
        cout << ans << " ";
        if(ans > 0) {
            a[ans] -= q;
            update(1, 1, n, ans, a[ans]);
            // cout << endl;
            // fo(i,1,n+1) cout << a[i] << ' ';
            // cout << endl;
        }
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