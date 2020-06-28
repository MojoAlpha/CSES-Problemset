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
int main()
{
    long t;
    cin>>t;
    while(t--){
        ll a,b;
        cin >> a >> b;

        ll gr, sm;
        if(a > b){
            gr = a;
            sm = b;
        }else{
            gr = b;
            sm = a;
        }
        ll x;
        x = gr - sm;
        if(sm - x == gr - 2*x && sm - x >= 0 && (sm - x) % 3 == 0)
          cout<< "YES\n";
        else
          cout<< "NO\n";
    }
    return 0;
}