#include <bits/stdc++.h>
#define ll long long
#define N 100005
#define M 10000005
#define O 1000000007
#define vi vector<int>
#define vl vector<long>
#define vb vector<bool>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long, long>
#define plll pair<long long, long long>
#define fo(i, b, n) for (ll i = b; i < n; ++i)
const double PI = 3.141592653589793238;
const ll oo = 1e18;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;

void solve()
{
    string s;
    ll n, k;
    cin >> n >> k;
    vll v(n, 0);
    fo(i, 0, n)
    {
        cin >> s;
        reverse(s.begin(), s.end());
        fo(j, 0, k) v[i] += (s[j] == '1') * (1 << j);
    }
    ll ans = 32;
    fo(i, 0, n)
        fo(j, i + 1, n)
            ans = min(ans, (ll)__builtin_popcount(v[i] ^ v[j]));
    cout << ans;
}

int main()
{
    fast;
    solve();
    return 0;
}