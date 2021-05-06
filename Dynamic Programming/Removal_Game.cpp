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
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;

vector<vll> dp;
long n;

ll getVal(long x, long y) {
    if(x > n || y > n)
        return 0;
    return dp[x][y];
}

int main()
{
    fast;
    cin >> n;
    vl a(n);
    fo(i, n) cin >> a[i];

    dp.resize(n + 1);
    fo(i, n + 1) dp[i].resize(n + 1, 0);

    for(long i = n; i > 0; --i) {
        for(long j = i; j <= n; ++j) {
            if(i == j)
                dp[i][j] = a[i - 1];
            else {
                dp[i][j] = max({ getVal(i + 1, j - 1) + a[i - 1], getVal(i + 1, j - 1) + a[j - 1], getVal(i + 2, j) + a[i - 1], getVal(i, j - 2) + a[j - 1] });
            }
        }
    }

    cout << dp[1][n];

    return 0;
}