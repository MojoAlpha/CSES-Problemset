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

// Sparse Table
long dp[20][200005];

int main()
{
    fast;
    long n, q, x = 1;
    cin >> n >> q;
    fo(i, n) cin >> dp[0][i];

    while ((1 << x) <= n)
    {
        long d = (1 << x);
        for (long i = 0; i < n - d + 1; ++i)
            dp[x][i] = min(dp[x - 1][i], dp[x - 1][i + d / 2]);
        x++;
    }

    while (q--)
    {
        long l, r;
        cin >> l >> r;
        long k = log2(r - l + 1);
        cout << min(dp[k][l - 1], dp[k][r - (1 << k)]) << endl;
    }

    return 0;
}