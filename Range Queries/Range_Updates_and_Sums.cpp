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
 
ll n, q, qr, a, b, x;
ll st[4 * sz], lazy[4 * sz][2], ar[sz];
 
void upd(ll id) {
    st[id] = st[2 * id] + st[2 * id + 1];
}
 
void lazy_update(ll id, ll lt, ll rt) {
    if(lazy[id][0] > 0) {
        if(lt != rt) {
            ll mid = (lt + rt) / 2;
            st[2 * id] += lazy[id][0] * (mid - lt + 1);
            st[2 * id + 1] += lazy[id][0] * (rt - mid);
            lazy[2 * id][0] += lazy[id][0];
            lazy[2 * id + 1][0] += lazy[id][0];
        }
        lazy[id][0] = 0;
    }
    if(lazy[id][1] > 0) {
        if(lt != rt) {
            ll mid = (lt + rt) / 2;
            st[2 * id] = lazy[id][1] * (mid - lt + 1);
            st[2 * id + 1] = lazy[id][1] * (rt - mid);
            lazy[2 * id][1] = lazy[id][1];
            lazy[2 * id + 1][1] = lazy[id][1];
        }
        lazy[id][1] = 0;
    }
}
 
void build(ll id, ll lt, ll rt) {
    if(lt == rt) {
        st[id] = ar[lt];
        return;
    }
    ll mid = (lt + rt) / 2;
    build(2 * id, lt, mid);
    build(2 * id + 1, mid + 1, rt);
    upd(id);
}
 
void update(ll id, ll lt, ll rt, ll lr, ll rr, ll val, ll type) {
    if(lr > rr) return;
    if(lr == lt && rr == rt) {
        if(type == 0) {
            st[id] += val * (rt - lt + 1);
            lazy[id][type] += val;
        }
        else {
            st[id] = val * (rt - lt + 1);
            lazy[id][type] = val;
        }
        return;
    }
    lazy_update(id, lt, rt);
    ll mid = (lt + rt) / 2;
    update(2 * id, lt, mid, lr, min(rr, mid), val, type);
    update(2 * id + 1, mid + 1, rt, max(mid + 1, lr), rr, val, type);
    upd(id);
}
 
ll query(ll id, ll lt, ll rt, ll lr, ll rr) {
    if(lr > rr) return 0;
    if(lr == lt && rr == rt) return st[id];
    lazy_update(id, lt, rt);
    ll mid = (lt + rt) / 2;
    return query(2 * id, lt, mid, lr, min(mid, rr)) + query(2 * id + 1, mid + 1, rt, max(lr, mid + 1), rr);
}
 
void solution(ll testno) {
    cin >> n >> q;
    fo(i,1,n+1) cin >> ar[i];
    build(1, 1, n);
 
    while(q--) {
        cin >> qr;
        if(qr == 1) {
            cin >> a >> b >> x;
            update(1, 1, n, a, b, x, 0);
        }
        else if(qr == 2) {
            cin >> a >> b >> x;
            update(1, 1, n, a, b, x, 1);
        }
        else {
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << endl;
        }
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