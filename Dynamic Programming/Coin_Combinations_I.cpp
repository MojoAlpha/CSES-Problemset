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
    ll dp[x + 1], a[n];
    dp[0] = 0;
    for(i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for(i = 1; i <= x; ++i) {
        long j = 0;
        dp[i] = 0;
        while(j < n) {
            if(i - a[j] > 0)
                dp[i] += dp[i - a[j]];
            else if(i - a[j] == 0)
                dp[i] += 1;
            dp[i] = dp[i] % 1000000007;
            ++j;
        }
    }
    cout << dp[x] << endl;
    return 0;
}