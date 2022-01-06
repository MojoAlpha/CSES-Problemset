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

struct Point {
    ll x, y;
    void getPoint() {
        cin >> x >> y;
    }
};
struct Line {
    Point p1, p2;
    void getLine() {
        p1.getPoint();
        p2.getPoint();
    }
};
// 0 :- Collinear | 1 :- Clockwise | 2 :- AntiClockwise
int getOrientation(Point p, Point q, Point r) {
    ll val = (q.y - p.y) * (r.x - q.x) - (r.y - q.y) * (q.x - p.x);
    if(val == 0) return 0;
    return (val > 0 ? 1 : 2);
}
bool onSegment(Point p, Point q, Point r) {
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));

}
bool doIntersect(Line l1, Line l2) {
    ll o1 = getOrientation(l1.p1, l1.p2, l2.p1);
    ll o2 = getOrientation(l1.p1, l1.p2, l2.p2);
    ll o3 = getOrientation(l2.p1, l2.p2, l1.p1);
    ll o4 = getOrientation(l2.p1, l2.p2, l1.p2);

    // general case
    if(o1 != o2 && o3 != o4) return true;

    // special case : COLLINEAR POINTS
    if(o1 == 0 && onSegment(l1.p1, l2.p1, l1.p2)) return true;
    if(o2 == 0 && onSegment(l1.p1, l2.p2, l1.p2)) return true;
    if(o3 == 0 && onSegment(l2.p1, l1.p1, l2.p2)) return true;
    if(o4 == 0 && onSegment(l2.p1, l1.p2, l2.p2)) return true;
    return false;
}

void solution(ll testno) {
    Line l1, l2;
    l1.getLine();
    l2.getLine();
    cout << (doIntersect(l1, l2) ? "YES" : "NO");
}

signed main()
{
    fastIO;
    ll test = 1;
    cin >> test;
    fo(i, 1, test + 1) {
        solution(i);
        cout << endl;
    }
    return 0;
}