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

signed main()
{
    fastIO;
    int n, k;
    cin >> n >> k;
    int a[n];
    fo(i, 0, n) cin >> a[i];

    pair<int, int> dp[1 << n];
    dp[0] = {0, k + 1};

    for (int s = 1; s < (1 << n); s++)
    {
        dp[s] = {25, 0};
        for (int i = 0; i < n; ++i)
        {
            if ((s >> i) & 1)
            {
                auto t = dp[s ^ (1 << i)];
                if (t.se + a[i] > k)
                {
                    t.fi++;
                    t.se = min(a[i], t.se);
                }
                else
                    t.se += a[i];
                dp[s] = min(dp[s], t);
            }
        }
    }

    cout << dp[(1 << n) - 1].fi;
    return 0;
}