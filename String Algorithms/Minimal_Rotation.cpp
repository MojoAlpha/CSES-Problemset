#include <bits/stdc++.h>

using namespace std;

#define N 100005
#define MOD 1000000007
#define fo(i, b, n) for (long i = b; i < n; ++i)
#define rfo(i, b, n) for (long i = b; i >= n; --i)
#define all(ar) ar.begin(), ar.end()
#define rall(ar) ar.rbegin(), ar.rend()
#define mem(ar, val) memset(ar, (val), sizeof(ar))
#define fi first
#define se second
#define pb push_back
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.precision(12);

typedef long long ll;
typedef pair<long, long> pll;
typedef pair<ll, ll> plll;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vl> vvl;
typedef vector<vll> vvll;

const double PI = 3.141592653589793238;
const ll oo = 1e18;

// Booth's Algorithm

string s;

signed main()
{
    fastIO;
    cin >> s;
    s = s + s;
    ll n = s.size(), i = 0, ans = 0;

    while (i < n / 2)
    {
        ans = i;
        ll k = i, j = i + 1;
        while (j < n && s[j] >= s[k])
        {
            if (s[j] == s[k])
                k++;
            if (s[j] > s[k])
                k = i;
            ++j;
        }
        while (i <= k)
            i += j - k;
    }
    cout << s.substr(ans, n / 2);
    return 0;
}