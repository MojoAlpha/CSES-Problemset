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
    long a, b;
    cin >> a >> b;
    
    vector<vl> dp(a + 1);
    fo(i, a + 1) dp[i].resize(b + 1, 0);

    for(long i = 1; i <= a; ++i) {
        for(long j = 1; j <= b; ++j) {
            if(i == j)
                continue;
            long mini = INT_MAX;
            for(long k = 1; k < i; ++k)
                mini = min(mini, dp[k][j] + dp[i - k][j] + 1);
            for(long k = 1; k < j; ++k)
                mini = min(mini, dp[i][k] + dp[i][j - k] + 1);
            dp[i][j] = mini;
        }
    }

    cout << dp[a][b];
    return 0;
}