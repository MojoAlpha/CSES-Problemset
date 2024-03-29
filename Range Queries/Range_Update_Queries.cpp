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

ll fenTree[2 * N], n, q, arr[2 * N];

ll sum(ll idx)
{
    ll res = 0;
    for (; idx >= 0; idx = (idx & (idx + 1)) - 1)
        res += fenTree[idx];
    return res;
}

void add(ll idx, ll val)
{
    for (; idx < n; idx = (idx | (idx + 1)))
        fenTree[idx] += val;
}

void solution() {}

signed main()
{
    fastIO;
    mem(fenTree, 0);

    cin >> n >> q;
    fo(i, 0, n) cin >> arr[i];

    while (q--)
    {
        ll query;
        cin >> query;
        if (query == 1)
        {
            ll lo, hi, val;
            cin >> lo >> hi >> val;
            add(lo - 1, val);
            if (hi < n)
                add(hi, -val);
        }
        else
        {
            ll ind;
            cin >> ind;
            cout << arr[ind - 1] + sum(ind - 1) << endl;
        }
    }
    return 0;
}