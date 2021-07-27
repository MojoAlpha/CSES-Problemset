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
    ll n;
    cin >> n;
    ll v = n % MOD, m = (v * v) % MOD, sum = (v * (v + 1) / 2) % MOD;

    fo(i, 1, sqrt(n))
    {
        if (n % i == 0)
        {
            sum = (sum - i + MOD) % MOD;
            if (i * i != n)
                sum = (sum - (n / i) + MOD) % MOD;
        }
    }
    n %= sum;
    cout << (m - n + MOD) % MOD;
}

signed main()
{

    fastIO;
    solution();
    return 0;
}