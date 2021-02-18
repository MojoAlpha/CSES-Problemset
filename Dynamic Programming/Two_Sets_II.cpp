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

int main()
{
    fast;
    ll n;
    cin >> n;
    ll S = n * (n + 1)  / 2;
    if(S % 2 != 0) {
        cout << "0";
        exit(0);
    }
    S /= 2;
    ll dp[n + 1][S + 1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    for(long i = 1; i < n + 1; ++i) {
        for(long j = 1; j < S + 1; ++j) {
            dp[i][j] = dp[i - 1][j];
            if(j - i >= 0)
                dp[i][j] += dp[i - 1][j - i];
            dp[i][j] %= 1000000007;
        }
    }

    cout << dp[n][S];
    return 0;
}