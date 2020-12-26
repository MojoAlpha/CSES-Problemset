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
    for(i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    long c[x + 1][n] = {0};
    dp[0] = 0;
    for(i = 1; i <= x; ++i) {
        int j = 0;
        while(j < n)
        {
            if(a[j] > i)
                break;
            if(i - a[j] == 0)
            {
                dp[i]++;
                c[i][j]++;
            }
            else
            {
                
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}