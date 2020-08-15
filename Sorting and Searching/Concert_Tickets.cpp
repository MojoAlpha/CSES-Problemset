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

ll binary_near(vll h, ll start, ll end, vll taken, ll val, ll ind){

    ll mid = (start + end) / 2;

    if(h[mid] > val)
        return binary_near(h, start, mid, taken, val, ind);
    
    if(h[mid] == val)
        return mid;

    if(h[mid] > h[ind] && taken[mid] == 0)
        return binary_near(h, mid, end , taken, val, mid);
    return binary_near(h, mid, end, taken, val, ind);
}

int main()
{
    ll n, m, i, j;
    cin >> n >> m;
    vll h(n), t(m), res(m), taken(n);
    for(i = 0; i < n; ++i)
        cin >> h[i];
    for(i = 0; i < m; ++i)
        cin >>t[i];
    for(i = 0; i < n; ++i)
        taken[i] = 0;
    sort(h.begin(), h.end());

    for(i = 0; i < m; ++i){
        ll ans = binary_near(h, 0, n - 1, taken, t[i], n - 1);
        cout << ans << endl;
    }

    for(i = 0; i < m; ++i)
        cout << res[i] << endl;
    return 0;
}