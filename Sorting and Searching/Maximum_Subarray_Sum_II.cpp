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
    ll n, a, b;
    cin >> n >> a >> b;
    vll x(n);
    fo(i, n) cin >> x[i];

    vll pre(n, 0);
    pre[0] = x[0];
    for (long i = 1; i < n; ++i)
        pre[i] = pre[i - 1] + x[i];

    multiset<ll> ms;
    ms.insert(0);
    ll ans = INT_MIN;
    ans = max(ans, pre[a - 1]);
    ll flag = 0;
    for (long i = a; i < n; ++i)
    {
        if (i - a >= 0 && flag == 0)
        {
            auto it = ms.find(0);
            ms.erase(it);
            flag = 1;
        }
        if (i - a >= 0)
            ms.insert(pre[i - a]);
        ans = max(ans, pre[i] - *ms.begin());
        if (i - b >= 0)
        {
            auto it = ms.find(pre[i - b]);
            ms.erase(it);
        }
    }
    cout << ans;
    return 0;
}