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
    long n;
    cin >> n;
    vector<pll> d(n);
    fo(i, n) cin >> d[i].first >> d[i].second;
    sort(d.begin(), d.end());
    long time = 0, res = 0;
    fo(i, n)
    {
        time += d[i].first;
        res += d[i].second - time;
    }
    cout << res;
    return 0;
}