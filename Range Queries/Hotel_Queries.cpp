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

ll n, m, t;

signed main()
{
    fastIO;
    cin >> n >> m;

    multiset<pll> ms;
    fo(i, 0, n)
    {
        cin >> t;
        ms.insert({t, i + 1});
    }

    fo(i, 0, m)
    {
        cin >> t;
        auto itr = ms.lower_bound({t, 0});
        if (itr == ms.end())
            cout << "0 ";
        else
        {
            ms.erase(itr);
            cout << (*itr).second << " ";
            ms.insert({(*itr).fi - t, (*itr).se});
        }
    }
    return 0;
}