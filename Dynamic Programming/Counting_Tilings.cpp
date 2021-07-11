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
    long n, m;
    cin >> n >> m;
    ll dp[n + 1][m + 1] = {0};
    memset(dp, 0, sizeof(dp));
    for (long i = 1; i <= m; ++i)
        if (i % 2 == 0)
            dp[1][i] = 1;

    if (n > 1)
    {
        dp[2][1] = 1;
        dp[2][2] = 2;
        for (long i = 3; i <= m; ++i)
            dp[2][i] = dp[2][i - 1] + dp[1][i] + dp[1][i - 2];
    }
}

int main()
{
    fast;
    // long t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}