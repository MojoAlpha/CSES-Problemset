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

ll mat[2][2] = {{1, 1}, {1, 0}};
ll res[2][2] = {{1, 0}, {0, 1}};

void multiply(ll a[2][2], ll b[2][2])
{
    ll tmp[2][2] = {{0, 0}, {0, 0}};
    fo(i, 0, 2)
    {
        fo(j, 0, 2)
        {
            fo(k, 0, 2)
                tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % MOD;
        }
    }

    fo(i, 0, 2) fo(j, 0, 2) a[i][j] = tmp[i][j];
}

void binPow(ll n)
{
    while (n)
    {
        if (n & 1)
            multiply(res, mat);
        multiply(mat, mat);
        n >>= 1;
    }
}

void solution()
{
    ll n;
    cin >> n;
    if (n == 0)
        cout << "0";
    else
    {
        binPow(n);
        cout << res[0][1];
    }
}

signed main()
{
    fastIO;
    solution();
    return 0;
}