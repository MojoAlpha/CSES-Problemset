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

pair<ll, ll> sop(pair<ll, ll> *a, ll start, ll end, ll x) {
    while(start < end) {
        if(a[start].first + a[end].first == x)
            return make_pair(start, end);
        else if(a[start].first + a[end].first < x)
            start++;
        else
            end--;
    }

    return make_pair(-1, -1);
}

int main()
{
    ll n, x, i, j;
    cin >> n >> x;
    pair<ll, ll> a[n];
    for(i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + n);

    for(i = 0; i < n; ++i) {
        for(j = i + 1; j < n; ++j) {
            if(a[i].first + a[j].first < x) {
                ll diff = x - (a[i].first + a[j].first);
                pair<ll, ll> val = sop(a, i + 1, j - 1, diff);

                if(val.first != -1) {
                    cout << a[i].second << " " << a[j].second << " " << a[val.first].second << " " << a[val.second].second;
                    return 0;
                }
            }
        }
    }
    
    cout << "IMPOSSIBLE";
    return 0;
}