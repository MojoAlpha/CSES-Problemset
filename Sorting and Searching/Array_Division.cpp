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

vll a(2 * N);
ll n, k;

bool divideGroups(ll val)
{
    int grps = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > val)
            return false;
        if (sum + a[i] > val)
        {
            ++grps;
            sum = 0;
        }
        sum += a[i];
    }
    if (sum > 0)
        grps++;
    return (grps <= k);
}

void solution()
{
    cin >> n >> k;
    fo(i, 0, n) cin >> a[i];

    ll lo = 0, hi = oo, ans = 0;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (divideGroups(mid))
        {
            hi = mid - 1;
            ans = mid;
        }
        else
            lo = mid + 1;
    }
    cout << ans << endl;
}

signed main()
{
    fastIO;
    solution();
    return 0;
}