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
ll sLow = 0, sUp = 0;

void ins(ll val) {
    ll a = *low.rbegin();
    if(a < val) {
        up.insert(val);
        sUp += val;
        if(up.size() > k / 2) {
            ll tmp = *up.begin();
            low.insert(tmp);
            sLow += tmp;
            up.erase(up.find(tmp));
            sUp -= tmp;
        }
    }
    else {
        low.insert(val);
        sLow += val;
        if(low.size() > (k + 1) / 2) {
            ll tmp = *low.rbegin();
            up.insert(tmp);
            sUp += tmp;
            low.erase(low.find(tmp));
            sLow -= tmp;
        }
    }
}

void er(ll val) {
    if(up.find(val) != up.end()) {
        up.erase(up.find(val));
        sUp -= val;
    }
    else {
        low.erase(low.find(val));
        sLow -= val;
    }
    
    if(low.empty()) {
        ll tmp = *up.begin();
        low.insert(tmp);
        sLow += tmp;
        up.erase(up.begin());
        sUp -= tmp;
    }
}

ll med() {
    return (k % 2 == 0) ? 0 : *low.rbegin();
}

int main()
{
    fast;
    cin >> n >> k;
    vll a(n);
    fo(i, n) cin >> a[i];

    low.insert(a[0]);
    sLow += a[0];
    for(long i = 1; i < k; ++i)
        ins(a[i]);
    
    cout << sUp - sLow + med();
    for(long i = k; i < n; ++i) {
        if(k == 1) {
            ins(a[i]);
            er(a[i - k]);
        }
        else {
            er(a[i - k]);
            ins(a[i]);
        }
        cout << " " << sUp - sLow + med();
    }
    return 0;
}