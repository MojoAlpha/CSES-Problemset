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
    long n;
    cin>>n;
    if(n == 1)
    printf("1\n");
    else if(n==2 || n==3)
    printf("NO SOLUTION\n");
    else
    {
        long i;
        for(i=2; i<=n; i+=2)
        printf("%ld ",i);
        for(i=1; i<=n; i+=2)
        printf("%ld ",i);
    }
    
    return 0;
}