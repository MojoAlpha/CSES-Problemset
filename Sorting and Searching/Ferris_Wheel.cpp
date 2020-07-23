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
    ll n, x, res = 0;
    cin >> n >> x;
    ll a[n], i, pos = 0, j;
    for(i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for(i = n - 1 ; i >= 0; --i)
        if(a[0] + a[i] <= x){
            pos = i;
            break;
        }
    res = n - 1 - pos;
    for(i = 0, j = pos; i <= j; )
    {
        if(i == j){
            res++;
            break;
        }
        if(a[i] + a[j] <= x){
            i++;
            j--;
            res++;
        }
        else
        {
            j--;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}