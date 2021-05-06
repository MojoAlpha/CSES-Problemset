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
#define plll pair<ll, ll>
#define fo(i, N) for (long i = 0; i < N; ++i)
#define fos(i, b, N) for (long i = b; i < N; ++i)
#define forr(i, N) for (long i = N; i >= 0; --i)
const double PI = 3.141592653589793238;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;

int main()
{
    ll n, k, res = 0;
    cin >> n >> k;
    vector<plll> a(n);
    fo(i, n) cin >> a[i].second >> a[i].first;
    sort(a.begin(), a.end());

    multiset<ll> end_time;
    fo(i, k) end_time.insert(0);

    for (long i = 0; i < n; ++i)
    {
        auto it = end_time.upper_bound(a[i].second);
        if (it == end_time.begin())
            continue;

        end_time.erase(--it);
        end_time.insert(a[i].first);
        ++res;
    }
    cout << res;
    return 0;
}