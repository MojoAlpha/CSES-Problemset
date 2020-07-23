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
        ll n, m, k, res = 0, i, j;
        cin >> n >> m >> k;
        vl a(n), b(m);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < m; ++i)
            cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(i = 0, j = 0 ; i < n && j < m; )
        {
            if(a[i] - b[j] > k)
                j++;
            else if(b[j] - a[i] > k)
                i++;
            else if(abs(a[i] - b[j]) <= k){
                i++;
                j++;
                res++;
            }
        }
        cout << res << endl;
    return 0;
}