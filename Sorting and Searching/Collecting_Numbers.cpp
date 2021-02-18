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
    long n;
    cin >> n;
    vl a(n);
    fo(i, n) cin >> a[i];

    ll res = 0;
    set<long> s;
    for(long i = 0; i < n; ++i) {
        s.insert(a[i]);
        auto it = s.lower_bound(a[i]);
        if(it == s.begin()) {
            res++;
        }
        else {
            s.erase(--it);
            s.insert(a[i]);
        }

        // auto itm = s.begin();
        // while(itm != s.end()) {
        //     cout << *itm << " ";
        //     ++itm;
        // }
        // cout << endl;
    }
    cout << s.size();
    return 0;
}