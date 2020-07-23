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
    long n, i, curr = -1, count = 1;
    cin >> n;
    long a[n];
    for(i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    curr = a[0];
    for( i = 1; i < n; ++i)
    {
        if(a[i] != curr){
            count++;
            curr = a[i];
        }
    }
    cout << count << endl;
    return 0;
}