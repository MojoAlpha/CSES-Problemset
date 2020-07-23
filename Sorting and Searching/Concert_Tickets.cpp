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
    ll n, m, i, j;
    cin >> n >> m;
    ll h[n];
    pair<ll, int> t[m];
    for(i = 0; i < n; ++i)
        cin >> h[i];
    for(i = 0; i < m; ++i){
        cin >>t[i].first;
        t[i].second = i;
    }
    sort(h, h + n);
    sort(t, t + m);
    ll res[m] = {-1};
    for(i = 0, j = 0; i < m && j < n ; ){
        if(t[i].first >= h[j]){
            res[t[i].second] = h[j];
            i++;
            j++;
        }
        else
            i++;
    }
    for(i = 0; i < m ; ++i)
        cout << res[i] << endl;
    return 0;
}