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
    long n, i, j;
    cin >> n;
    char s[n][n];
    ll dp[n][n] = {0};
    for(i = 0; i < n; ++i)
        for(j = 0; j < n; ++j)
            cin >> s[i][j];
    for(i = 0; i < n; ++i)
        if(s[0][i] == '*')
        {
            int k = i;
            while(k < n){
                dp[0][k] = 0;
                ++k;
            }
            break;
        }
        else
            dp[0][i] = 1;
    
    for(i = 0; i < n; ++i)
        if(s[i][0] == '*')
        {
            int k = i;
            while(k < n){
                dp[k][0] = 0;
                ++k;
            }
            break;
        }
        else
            dp[i][0] = 1;

    for(i = 1; i < n; ++i)
    {
        for(j = 1; j < n; ++j)
        {
            if(s[i][j] == '*')
                dp[i][j] = 0;
            else
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
        }
    }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}