#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000005
#define O 1000000007
#define vi vector<int>
#define vl vector<long>
#define vb vector<bool>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long, long>
#define fo(i, N) for (long i = 0; i < N; ++i)
#define fos(i, b, N) for (long i = b; i < N; ++i)
#define forr(i, N) for (long i = N; i >= 0; --i)
const double PI = 3.141592653589793238;
const ll oo = 1e18;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;

ll n, q;
vll lazy(4 * N, 0);
vll x(2 * N);

void updateLazy(ll start, ll end, ll lo, ll hi, ll k, ll pos)
{
    if (lo > hi)
        return;

    if (lazy[pos] != 0)
    {
    }
}

void solve()
{
    ll a, b, k, t;
    cin >> n >> q;
    fo(i, n) cin >> x[i];
    while (q--)
    {
        cin >> t;
        if (t == 2)
        {
            cin >> k;
            cout << x[k - 1] << " ";
        }
        else
        {
            cin >> a >> b >> k;
        }
    }
}

int main()
{
    fast;
    solve();
    return 0;
}