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
#define F first
#define S second
const double PI = 3.141592653589793238;
const ll oo = 1e18;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;

void solve()
{
    string s;
    cin >> s;
    long n = s.size();
    vl lps(n, 0);

    for (long i = 1; i < n; ++i)
    {
        long j = lps[i - 1];
        while (j > 0 && s[i] != s[j])
            j = lps[j - 1];
        if (s[i] == s[j])
            j++;
        lps[i] = j;
    }

    // fo(i, n) cout << lps[i] << " ";
    // cout << endl;

    vl res;
    long j = n - 1;
    while (j > 0 && lps[j] > 0)
    {
        res.push_back(lps[j]);
        if (lps[j - 1] > lps[j])
            break;
        j = lps[j - 1];
    }
    for (long i = res.size() - 1; i >= 0; --i)
        cout << res[i] << " ";
}

int main()
{
    fast;
    solve();
    return 0;
}