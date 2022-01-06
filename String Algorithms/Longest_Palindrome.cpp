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
const ll oo = 1e18;

void solution(ll testno) {
    string s;
    ll n, reso = 0, rese = 0, ind1 = -1, ind2 = -1;
    cin >> s;
    n = s.size();
    vll d1(n), d2(n);

    for(ll i = 0, l = 0, r = -1; i < n; ++i) {
        ll k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while(i - k >= 0 && i + k < n && s[i - k] == s[i + k])
            k++;
        d1[i] = k--;
        if(i + k > r) {
            l = i - k;
            r = i + k;
        }

        if(reso < d1[i]) {
            reso = d1[i];
            ind1 = i;
        }
    }

    for(ll i = 0, l = 0, r = -1; i < n; ++i) {
        ll k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while(i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k])
            k++;
        d2[i] = k--;
        if(i + k > r) {
            l = i - k - 1;
            r = i + k;
        }

        if(rese < d2[i]) {
            rese = d2[i];
            ind2 = i;
        }
    }

    if(reso > rese) cout << s.substr(ind1 - reso + 1, 2 * reso - 1);
    else cout << s.substr(ind2 - rese, 2 * rese);
}

signed main()
{
    fastIO;
    ll test = 1;
    // cin >> test;
    fo(i, 1, test + 1) {
        solution(i);
        cout << endl;
    }
    return 0;
}