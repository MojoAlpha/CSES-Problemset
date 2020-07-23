#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000007
#define O 1000000009
#define vll vector<long long>
#define dis(n) cout<<n<<endl
#define fo(i,N) for(int i=0; i<N; ++i)
#define fos(i,b,N) for(int i=b; i<N; ++i)
#define forr(i,N) for(i=N; i>=0; --i)

using namespace std;

ll rec_min(ll arr[], ll i, ll sumCalc, ll sumTot){
    if(i  == 0)
        return abs((sumTot - sumCalc) - sumCalc);

    return min(rec_min(arr, i - 1, sumCalc + arr[i - 1], sumTot), rec_min(arr, i -1, sumCalc, sumTot));
}

ll find_min(ll arr[], ll n){
    ll sum = 0, i;
    for(i = 0; i < n; ++i)
        sum += arr[i];
    return rec_min(arr, n, 0, sum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,i;
    cin >> n;
    ll a[n];
    for(i = 0; i < n; ++i)
        cin>>a[i];
    cout << find_min(a, n) << endl;
    return 0;
}