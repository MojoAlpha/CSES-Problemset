#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000007
#define O 1000000009
#define vll vector<long long>
#define vl vector<long>
#define dis(n) cout << n << endl
#define fo(i, N) for (int i = 0; i < N; ++i)
#define fos(i, b, N) for (int i = b; i < N; ++i)
#define forr(i, N) for (i = N; i >= 0; --i)
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;

multiset<ll> low;
multiset<ll> up;
long n, k;


void ins(ll val) {
    ll a = *low.rbegin();
    if(a < val) {
        up.insert(val);
        if(up.size() > k / 2) {
            low.insert(*up.begin());
            up.erase(up.begin());
        }
    }
    else {
        low.insert(val);
        if(low.size() > (k + 1) / 2) {
            up.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

void er(ll val) {
    if(up.find(val) != up.end())
        up.erase(up.find(val));
    else
        low.erase(low.find(val));
    
    if(low.empty()) {
        low.insert(*up.begin());
        up.erase(up.begin());
    }
}

int main()
{
    fast;
    cin >> n >> k;
    vll a(n);
    fo(i, n) cin >> a[i];

    low.insert(a[0]);
    for(long i = 1; i < k; ++i)
        ins(a[i]);
    
    cout << *low.rbegin() << " ";
    for(long i = k; i < n; ++i) {
        if(k == 1) {
            ins(a[i]);
            er(a[i - k]);
        }
        else {
            er(a[i - k]);
            ins(a[i]);
        }
        cout << *low.rbegin() << " ";
    }
    return 0;
}