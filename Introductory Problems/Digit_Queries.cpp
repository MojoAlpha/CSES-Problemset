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
    
    int q;
    cin >> q;
    while(q--) {
        ll k;
        cin >> k;

        ll f = 9, d = 1;
        while(1)  {
            if(k <= f * d) {
                ll pl = k / d, ;
                ll v = pow(10, d) - 1;

                break;
            }
            else
            {
                k -= f * d;
                f *= 10;
                d++;
            }
        }
    }

    return 0;
}