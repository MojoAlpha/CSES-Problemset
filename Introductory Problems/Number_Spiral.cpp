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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long t;
    cin>>t;
    while(t--){
        long x,y;
        ll val;
        cin>>x>>y;
        long maxim = max(x,y);
        if(maxim == x)
        {
            if(x % 2 == 0)
            {
                val = x * x;
                val -= y - 1;
            }
            else
            {
                x--;
                val = x * x;
                val += y;
            }
        }
        else
        {
            if(y % 2 == 1)
            {
                val = y * y;
                val -= x - 1;
            }
            else
            {
                y--;
                val = y * y;
                val += x;
            }   
        }
        cout<<val<<endl;
    }
    return 0;
}