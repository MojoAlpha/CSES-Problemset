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
const ll sz = 10 * N;

ll lpf[sz], mobius[sz], cnt[sz], n, x;

void least_prime_factor() {
    for(ll i = 2; i < sz; ++i) {
        if(!lpf[i]) {
            for(ll j = i; j < sz; j += i)
                if(!lpf[j]) lpf[j] = i;
        }
    }
}

void mobius_calculate() {
    for(ll i = 1; i < sz; ++i) {
        if(i == 1) mobius[i] = 1;
        else {
            if(lpf[i / lpf[i]] == lpf[i]) mobius[i] = 0;
            else mobius[i] = -1 * mobius[i / lpf[i]];
        }
    }
}

void solution(ll testno) {
    cin >> n;
    fo(i,0,n) {
        cin >> x;
        cnt[x]++;
    }
    ll ans = 0;

    fo(i,1,sz) {
        if(mobius[i] == 0) continue;
        ll d = 0;
        for(ll j = i; j < sz; j += i)
            d += cnt[j];
        ans += ((d * (d - 1)) / 2) * mobius[i];
    }
    cout << ans;
}

signed main()
{
    fastIO;
    least_prime_factor();
    mobius_calculate();
    ll test = 1;
    // cin >> test;
    fo(i, 1, test + 1) {
        solution(i);
        cout << endl;
    }
    return 0;
}