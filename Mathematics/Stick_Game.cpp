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

void solution()
{
    ll n, k;
    cin >> n >> k;
    vll a(k);
    fo(i, 0, k) cin >> a[i];

    vb dp(n + 1, 0);

    fo(i, 1, n + 1)
    {
        fo(j, 0, k)
        {
            if (i - a[j] >= 0 && dp[i - a[j]] == 0)
            {
                dp[i] = 1;
                break;
            }
        }
    }

    fo(i, 1, n + 1) cout << (dp[i] ? 'W' : 'L');
}

signed main()
{
    fastIO;
    solution();
    return 0;
}