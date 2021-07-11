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
    vector<vl> dp(n, vl(m + 1, 0));
    long x;
    cin >> x;
    if (x == 0)
        fill(dp[0].begin(), dp[0].end(), 1);
    else
        dp[0][x] = 1;

    for (long i = 1; i < n; ++i)
    {
        cin >> x;
        if (x == 0)
        {
            for (long j = 1; j <= m; ++j)
                for (long k : {j - 1, j, j + 1})
                    if (k >= 1 && k <= m)
                        (dp[i][j] += dp[i - 1][k]) %= O;
        }
        else
        {
            for (long k : {x - 1, x, x + 1})
                if (k >= 1 && k <= m)
                    (dp[i][x] += dp[i - 1][k]) %= O;
        }
    }
    long ans = 0;
    for (long j = 1; j <= m; ++j)
        (ans += dp[n - 1][j]) %= O;
    cout << ans;
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