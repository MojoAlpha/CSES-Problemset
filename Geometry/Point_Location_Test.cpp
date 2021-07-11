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

bool isLeft(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    return ((y2 - y1) * (x3 - x1) - (y3 - y1) * (x2 - x1)) < 0;
}

bool isRight(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    return ((y2 - y1) * (x3 - x1) - (y3 - y1) * (x2 - x1)) > 0;
}

void solve()
{
    ll x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if (isLeft(x1, y1, x2, y2, x3, y3))
        cout << "LEFT\n";
    else if (isRight(x1, y1, x2, y2, x3, y3))
        cout << "RIGHT\n";
    else
        cout << "TOUCH\n";
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