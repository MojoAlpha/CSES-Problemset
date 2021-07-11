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
typedef pair<pll, long> ppll;

const double PI = 3.141592653589793238;
const ll oo = 1e18;

struct Tourist
{
    long beg, end, ind;
};

struct TouristCmp
{
    bool operator()(Tourist &a, Tourist &b)
    {
        return (a.end < b.end);
    }
};

bool touristBegCmp(Tourist &a, Tourist &b)
{
    return (a.beg < b.beg);
}

bool touristEndCmp(Tourist &a, Tourist &b)
{
    return (a.end < b.end);
}

ll n;
vector<pair<pll, long>> v;
vl ans;

void solution()
{
    cin >> n;
    v.resize(n);
    ans.resize(n);

    fo(i, 0, n)
    {
        cin >> v[i].fi.fi >> v[i].fi.se;
        v[i].se = i;
    }
    sort(all(v));

    ll rooms = 0, last = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    for (long i = 0; i < n; ++i)
    {
        if (pq.empty())
        {
            last++;
            pq.push({v[i].fi.se, last});
            ans[v[i].se] = last;
        }
        else
        {
            pll mini = pq.top();
            if (mini.fi < v[i].fi.fi)
            {
                pq.pop();
                pq.push({v[i].fi.se, mini.se});
                ans[v[i].se] = mini.se;
            }
            else
            {
                last++;
                pq.push({v[i].fi.se, last});
                ans[v[i].se] = last;
            }
        }
        rooms = max(rooms, ll(pq.size()));
    }

    cout << rooms << endl;
    fo(i, 0, n) cout << ans[i] << " ";
}

signed main()
{
    fastIO;
    solution();
    return 0;
}