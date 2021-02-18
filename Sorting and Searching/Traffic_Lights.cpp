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
    long x, n;
    cin >> x >> n;
    multiset<long, less<long>> m, sizes;
    vl a(n);
    fo(i, n) cin >> a[i];
    m.insert(0);
    m.insert(x);
    sizes.insert(x);

    for(long i = 0; i < n; ++i) {
        auto it1 = m.upper_bound(a[i]);
        auto it2 = it1;
        --it1;
        m.insert(a[i]);
        
        auto si = sizes.find(*it2 - *it1);
        sizes.erase(si);
        sizes.insert(a[i] - *it1);
        sizes.insert(*it2 - a[i]);
        auto itr = sizes.end();
        --itr;
        cout << *itr << " ";
    }
    
    return 0;
}