#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000007
#define O 1000000009
#define vll vector<long long>
#define vl vector<long>
#define dis(n) cout<<n<<endl
#define fo(i,N) for(int i=0; i<N; ++i)
#define fos(i,b,N) for(int i=b; i<N; ++i)
#define forr(i,N) for(i=N; i>=0; --i)

using namespace std;
int main()
{
    long n, x, i;
    cin >> n >> x;
    vll dp(x + 1, 0), a(n);
    for(i = 0; i < n; ++i)
        cin >> a[i];

    dp[0] = 1;
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= x; ++j) {
            if(j - a[i - 1] >= 0) {
                dp[j] += dp[j - a[i - 1]];
                dp[j] = dp[j] % 1000000007;
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}