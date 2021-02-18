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
    int n;
    cin >> n;
    vi a(n);
    fo(i, n) cin >> a[i];

    int sum = accumulate(a.begin(), a.end(), 0);
    int dp[sum + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for(int i = 0; i < n; ++i) {
        for(int j = sum; j >= a[i]; --j)
            if(dp[j - a[i]] == 1)
                dp[j] = 1;
    }

    cout << accumulate(dp, dp + sum, 0) << endl;
    fo(i, sum) {
        if(dp[i + 1] == 1)
            cout << i + 1 << " ";
    }


    return 0;
}