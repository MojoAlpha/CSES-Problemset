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

// dp[i][j][k][l] - count of numbers where j is not present at ith index in number
// k denotes if the number contains leading zeros
// l denotes if the number has tight constraints

ll dp[20][10][2][2];

ll countNumbers(string &num, int n, int x, bool lead_zero, bool tight)
{
    if (n == 0)
        return 1;

    if (x != -1 && dp[n][x][lead_zero][tight] != -1)
        return dp[n][x][lead_zero][tight];

    // lower bound & upper bound
    int lb = 0;
    int ub = tight ? (num[num.size() - n] - '0') : 9;

    ll ans = 0;
    for (int i = lb; i <= ub; ++i)
    {
        if (i == x && lead_zero == 0)
            continue;
        ans += countNumbers(num, n - 1, i, (lead_zero && i == 0), (tight && i == ub));
    }
    return dp[n][x][lead_zero][tight] = ans;
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    string A, B;
    A = to_string(a - 1);
    B = to_string(b);
    memset(dp, -1, sizeof(dp));
    ll ansB = countNumbers(B, B.size(), -1, 1, 1);
    memset(dp, -1, sizeof(dp));
    ll ansA = countNumbers(A, A.size(), -1, 1, 1);
    cout << ansB - ansA;
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