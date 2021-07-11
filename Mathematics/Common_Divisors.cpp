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
const ll oo = 1e18;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;

vll cnt(1000000, 0);

int main()
{
    long n;
    cin >> n;
    vl a(n);
    fo(i, n)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (long i = 1000000; i >= 1; --i)
    {
        ll d = 0;
        for (long j = i; j <= 1000000; j += i)
            d += cnt[j];
        if (d >= 2)
        {
            cout << i;
            return 0;
        }
    }

    return 0;
}