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
const ll oo = 9e18;
const double EPS = 1e-6;

ll n, x, y;
vector<pll> pts;

ll euclideanDistance(pll a, pll b) {
    ll dx = a.fi - b.fi, dy = a.se - b.se;
    return dx * dx + dy * dy;
}

ll closest_points() {
    set<pll> st;
    st.insert({pts[0].se, pts[0].fi});
    ll left = 0, res = oo;
    for(ll i = 1; i < n; ++i) {
        ll dd = ceil(sqrt(res));
        while(left < i && pts[i].fi - pts[left].fi > res) {
            st.erase({pts[left].se, pts[left].fi});
            left++;
        }

        auto lt = st.lower_bound({pts[i].se - dd, 0});
        auto rt = st.upper_bound({pts[i].se + dd, 0});
        for(auto it = lt; it != rt; ++it)
            res = min(res, euclideanDistance({it->se, it->fi}, pts[i]));
        st.insert({pts[i].se, pts[i].fi});
    }

    return res;
}

signed main()
{
    fastIO;
    cin >> n;
    fo(i,0,n) {
        cin >> x >> y;
        pts.pb({x, y});
    }
    sort(all(pts));
    cout << closest_points();
    return 0;
}