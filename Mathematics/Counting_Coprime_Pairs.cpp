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
const ll V = 10 * N;

ll n, a[N];
vl primes;
int vis[V];

signed main()
{
    fastIO;

    fo(i, 2, V)
    {
        if (!vis[i])
        {
            primes.pb(i);
            for (ll j = i * i; j < V; j += i)
                vis[j] = 1;
        }
    }

    cin >> n;
    fo(i, 0, n) cin >> a[i];
    ll res = n * (n - 1) / 2, cnt = 0;

    fo(i, 0, primes.size())
    {
        cnt = 0;
        fo(j, 0, n) if (a[j] % primes[i] == 0) cnt++;

        res -= (cnt * (cnt - 1) / 2);
    }
    cout << res;

    return 0;
}