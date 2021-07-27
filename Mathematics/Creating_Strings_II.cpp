#include <bits/stdc++.h>

using namespace std;

#define N 100005
#define MOD 1000000007
#define fo(i, b, n) for (long i = b; i < n; ++i)
#define rfo(i, b, n) for (long i = b; i >= n; --i)
#define all(ar) ar.begin(), ar.end()
#define rall(ar) ar.rbegin(), ar.rend()
#define mem(ar, val) memset(ar, val, sizeof(ar))
#define fi first
#define se second
#define pb push_back
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.precision(12);

typedef long long ll;
typedef pair<long, long> pll;
typedef pair<ll, ll> plll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vl> vvl;
typedef vector<vll> vvll;

const double PI = 3.141592653589793238;
const ll oo = 1e18;

string s;
ll fact[10 * N];

ll binPow(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}

void solution()
{
    cin >> s;
    ll n = s.size();
    fact[0] = fact[1] = 1;
    fo(i, 2, 10 * N) fact[i] = (fact[i - 1] * i) % MOD;

    vll cnt(26, 0);
    fo(i, 0, n) cnt[s[i] - 'a']++;
    ll res = fact[n], inv = 1;
    fo(i, 0, 26)
    {
        if (cnt[i] > 1)
            inv = (inv * fact[cnt[i]]) % MOD;
    }
    res = (res * binPow(inv, MOD - 2)) % MOD;
    cout << res;
}

signed main()
{
    fastIO;
    solution();
    return 0;
}