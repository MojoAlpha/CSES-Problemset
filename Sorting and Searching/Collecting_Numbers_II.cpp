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

int giveDifference(vll &a, ll i1, ll i2)
{
    if (i1 > i2)
        return giveDifference(a, i2, i1);

    int res = 0;
    if (i1 > 1 && a[i1] < a[i1 - 1])
        res++;
    if (i1 < a.size() && a[i1] > a[i1 + 1])
        res++;

    if (i2 - i1 > 1 && a[i2] < a[i2 - 1])
        res++;
    if (i2 < a.size() && a[i2] > a[i2 + 1])
        res++;

    return res;
}

void solution()
{
    ll n, m;
    cin >> n >> m;
    vll a(n + 1);
    fo(i, 1, n + 1) cin >> a[i];

    vll pos(n + 1);
    fo(i, 1, n + 1) pos[a[i]] = i;

    ll res = 1;
    fo(i, 2, n + 1)
    {
        if (pos[i] < pos[i - 1])
            res++;
    }

    while (m--)
    {
        ll ai, bi;
        cin >> ai >> bi;

        ll i1 = pos[a[ai - 1]], i2 = pos[a[bi - 1]];
        int diff1 = giveDifference(pos, a[ai], a[bi]);

        swap(pos[a[ai]], pos[a[bi]]);
        swap(a[ai], a[bi]);

        int diff2 = giveDifference(pos, a[bi], a[ai]);
        res += diff2 - diff1;
        cout << res << endl;
    }
}

signed main()
{
    fastIO;
    solution();
    return 0;
}