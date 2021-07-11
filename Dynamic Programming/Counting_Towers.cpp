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

ll dp[1000006][2];

//                                      _  _
// dp[i][1] = last blocks are separate | || |
//                                   _ _
// dp[i][2] = last blocks are fused |   |

// transition:
//              _  _    _  _    _  _    _  _     _ _
//  _  _       | || |  |_|| |  | ||_|  |_||_|   |_ _|
// | || | =>   | || |, | || |, | || |, | || |,  | | |
//              _ _    _ _    _ _
//  _ _        |   |  |_|_|  |_ _|
// |   |  =>   |   |, |   |, |   |

// dp[i][0] = dp[i-1][0]*4 + dp[i-1][1]
// dp[i][1] = dp[i-1][0] + dp[i-1][1]*2

void solve()
{
    long n;
    cin >> n;
    cout << (dp[n][0] + dp[n][1]) % O << endl;
}

int main()
{
    fast;
    dp[1][0] = dp[1][1] = 1;
    for (long i = 2; i < 1000004; ++i)
    {
        dp[i][0] = (dp[i - 1][0] * 4 % O + dp[i - 1][1]) % O;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 2) % O;
    }

    long t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}