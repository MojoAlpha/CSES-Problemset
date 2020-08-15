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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n;
    cin >> n;
    ll dp[1000000], i;
    dp[1] = 1;
    for(i = 2; i <= 6; ++i)
    {
        dp[i] = 1;
        for(int j = 1; j < i; ++j)
            dp[i] += dp[j];
    }
    if(n <= 6)
        cout << dp[n] << endl;
    else
    {
        for(i = 7; i <= n; ++i){
            dp[i] = 0;
            dp[i] += (dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6]) % 1000000007;
        }
        cout << dp[n] << endl;
    }
    
    return 0;
}