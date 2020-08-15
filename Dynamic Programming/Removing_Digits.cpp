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
    long n, i;
    cin >> n;
    long dp[n + 1];
    dp[0] = 0;
    for(i = 1; i <= n; ++i) {
        long min = INT_MAX, t = i;
        while(t) {
            if(t % 10 != 0 && 1 + dp[i - t % 10] < min)
                min = 1 + dp[i - t % 10];
            t /= 10;
        }
        dp[i] = min;
    }
    cout << dp[n] << endl;
    return 0;
}