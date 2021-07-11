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
    long n, q;
    cin >> n >> q;
    vector<string> frst(n);
    fo(i, n) cin >> frst[i];
    vector<vi> dp(n + 1, vi(n + 1, 0));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (frst[i - 1][j - 1] == '*')
                dp[i][j]++;
            dp[i][j] += (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]);
        }

    while (q--)
    {
        long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << endl;
    }
}

int main()
{
    fast;
    solve();
    return 0;
}