#include <bits/stdc++.h>

using namespace std;

#define N 100005
#define MOD 1000000007
#define fo(i, b, n) for (long i = b; i < n; ++i)
#define rfo(i, b, n) for (long i = b; i >= n; --i)
#define all(ar) ar.begin(), ar.end()
#define rall(ar) ar.rbegin(), ar.rend()
#define mem(ar, val) memset(ar, (val), sizeof(ar))
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

void solution() {}

signed main()
{
    fastIO;
    ll n;
    map<ll, ll> com;
    cin >> n;
    vll a(n), b(n), c(n);
    fo(i, 0, n)
    {
        cin >> a[i] >> b[i] >> c[i];
        b[i]++;
        com[a[i]], com[b[i]];
    }

    ll coords = 0;
    for (auto &v : com)
        v.second = coords++;

    vector<vector<plll>> proj(coords);
    fo(i, 0, n) proj[com[b[i]]].emplace_back(com[a[i]], c[i]);

    vll dp(coords, 0);
    fo(i, 0, coords)
    {
        if (i > 0)
            dp[i] = dp[i - 1];
        for (auto x : proj[i])
            dp[i] = max(dp[i], dp[x.fi] + x.se);
    }

    cout << dp[coords - 1] << endl;
    return 0;
}