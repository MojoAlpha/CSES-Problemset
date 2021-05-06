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

long checkCase(vl a, long ind) {
    long n = a.size(), res = 0;
    if(ind - 1 >= 0 && a[ind] < a[ind - 1])
        res++;
    if(ind + 1 < n && a[ind] > a[ind + 1])
        res++;
    return res;
}

int main()
{
    long n, m;
    cin >> n >> m;
    vl a(n);
    fo(i, n) cin >> a[i];

    vl b(n);
    fo(i, n) b[a[i] - 1] = i;
    long res = 1;

    for(long i = 1; i < n; ++i)
        if(b[i] < b[i - 1])
            res++;
    
    for(long i = 0; i < m; ++i) {
        long x, y;
        cin >> x >> y;
        long prev = checkCase(a, x - 1) + checkCase(a, y - 1);
        swap(a[x - 1], a[y - 1]);
        long curr = checkCase(a, x - 1) + checkCase(a, y - 1);
        res += curr - prev;
        cout << res << endl;
    }

    return 0;
}