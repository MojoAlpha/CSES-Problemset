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
    cin >> n >> x;
    vll a(n);
    fo(i, n) cin >> a[i];

    ll tsum = 0, i = 0, res = 0, j = 0;
    while (i < n && tsum < x)
        tsum += a[i++];

    if (tsum == x)
        res++;

    while (i <= n)
    {
        if (tsum < x)
            tsum += a[i++];
        else
            tsum -= a[j++];

        if (tsum == x)
            res++;
    }

    cout << res;
    return 0;
}