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

    multiset<pair<long, long>, less<pair<long, long>>> arr;

    for(long i = 0; i < n; ++i) {
        arr.insert(make_pair(a[i], i + 1));
        auto it = arr.lower_bound(make_pair(a[i], i + 1));

        if(it != arr.begin()) {
            --it;
            cout << (*it).second << " ";
        }
        else
            cout << "0 ";
        
        for(auto itr = arr.begin(); itr != arr.end(); ++itr)
            cout << (*itr).first << "-" << (*itr).second << " ";
        cout << endl;
    }

    return 0;
}