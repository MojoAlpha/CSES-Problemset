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

void solve()
{
    ll n, q, x, l, r;
    cin >> n >> q;
    vll xors(n + 1, 0);
    fo(i, n)
    {
        cin >> x;
        xors[i + 1] = xors[i] ^ x;
    }

    while (q--)
    {
        cin >> l >> r;
        cout << (xors[r] ^ xors[l - 1]) << endl;
    }
}

int main()
{
    fast;
    solve();
    return 0;
}