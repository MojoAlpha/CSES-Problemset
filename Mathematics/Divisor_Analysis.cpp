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

ll n, a[N][2], r1, r2, r3;

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

ll inverse(ll val)
{
    if (val <= 1)
        return val;
    return binPow(val, MOD - 2) % MOD;
}

ll funcR2(ll val, ll po)
{
    ll inv = inverse(val - 1);
    return ((binPow(val, po) - 1) * inv) % MOD;
}

signed main()
{
    fastIO;
    r1 = r2 = r3 = 1;
    ll cnt = 1;
    cin >> n;
    fo(i, 0, n)
    {
        cin >> a[i][0] >> a[i][1];
        r1 = (r1 * (a[i][1] + 1)) % MOD;
        r2 = (r2 * funcR2(a[i][0], a[i][1] + 1)) % MOD;
        r3 = binPow(r3, a[i][1] + 1) * binPow(binPow(a[i][0], a[i][1] * (a[i][1] + 1) / 2), cnt) % MOD;
        cnt = cnt * (a[i][1] + 1) % (MOD - 1);
    }

    cout << r1 << " " << r2 << " " << r3;
    return 0;
}