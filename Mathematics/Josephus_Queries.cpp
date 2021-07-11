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

long joshephusFunc(long n, long k)
{
    if (n == 1)
        return 1;
    if (k <= (n + 1) / 2)
    {
        if (2 * k > n)
            return (2 * k) % n;
        else
            return 2 * k;
    }
    long tmp = joshephusFunc(n / 2, k - (n + 1) / 2);
    if (n & 1)
        return 2 * tmp + 1;
    return 2 * tmp - 1;
}

void solve()
{
    long n, k;
    cin >> n >> k;
    cout << joshephusFunc(n, k) << endl;
}

int main()
{
    fast;
    long t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}