#include <bits/stdc++.h>

using namespace std;

#define N 100005
#define MOD 1000000007
#define fo(i, b, n) for (long i = b; i < n; ++i)
#define rfo(i, b, n) for (long i = b; i >= n; --i)
#define all(ar) ar.begin(), ar.end()
#define rall(ar) ar.rbegin(), ar.rend()
#define mem(ar, val) memset(ar, val, sizeof(ar))
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

void solution()
{
    ll n;
    cin >> n;
    vector<pair<pll, long>> a(n);
    fo(i, 0, n)
    {
        cin >> a[i].fi.se >> a[i].fi.fi;
        a[i].se = i;
    }
    sort(all(a));
    vl ar1(n, 0), ar2(n, 0);

    long i = 0, j = 1;
    while (j < n)
    {
        if (a[i].fi.se >= a[j].fi.se)
        {
            ar1[a[i].se] = 1;
            ar2[a[j].se] = 1;
        }
        else
            i = j;
        ++j;
    }
    fo(i, 0, n) cout << ar1[i] << " ";
    cout << endl;
    fo(i, 0, n) cout << ar2[i] << " ";
}

signed main()
{
    fastIO;
    solution();
    return 0;
}