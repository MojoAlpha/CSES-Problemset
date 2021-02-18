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
    long n;
    cin >> n;
    vll a(n);
    fo(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll res = 1;

    if(a[0] != 1)
        cout << "1\n";
    else
    {
        for(long i = 1; i < n; ++i) {
            if(a[i] <= res + 1)
                res += a[i];
            else
                break;
        }
        cout << res + 1;
    }
    
    return 0;
}