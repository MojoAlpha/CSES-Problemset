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
    long n, x, i, j;
    cin >> n >> x;
    pair<long, long> a[n];
    for(i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + n);
    for(i = 0, j = n - 1; i < j;) {
        if(a[i].first + a[j].first == x)
            break;
        else if(a[i].first + a[j].first > x)
            j--;
        else
            i++;
    }
    if(i < j)
        cout << a[i].second << " " << a[j].second;
    else
        cout << "IMPOSSIBLE";
    return 0;
}