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
    long n;
    ll sum = 0;
    cin >> n;
    vll a(n);
    fo(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }

    vector<vll> dp(n, vll(n, 0));
    for (long l = n - 1; l >= 0; --l)
    {
        for (long r = l; r < n; ++r)
        {
            if (l == r)
                dp[l][r] = a[l];
            else
                dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
        }
    }
    cout << (sum + dp[0][n - 1]) / 2 << endl;

    return 0;
}