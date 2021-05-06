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

using namespace std;
int main()
{
    ll n, x;
    cin >> n;
    vll a(n);
    fo(i, n) cin >> a[i];

    ll res = 0;
    ll prefix_sum = 0;
    map<ll, ll> mods;
    mods[0] = 1;

    for (ll num : a)
    {
        prefix_sum += num;
        res += mods[prefix_sum % n];
        mods[prefix_sum % n]++;
    }
    cout << res << endl;
    return 0;
}