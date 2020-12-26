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
    long n, x, i, j;
    cin >> n >> x;
    vl h(n), s(n);
    fo(i, n) cin >> h[i];
    fo(i, n) cin >> s[i];
    long dp[n + 1][x + 1];
    fo(i, x + 1) dp[0][i] = 0;
    fo(i, n + 1) dp[i][0] = 0;
    
    for(i = 1; i <= x; ++i) {
        for(j = 1; j <= n; ++j) {
            
        }
    }
    return 0;
}