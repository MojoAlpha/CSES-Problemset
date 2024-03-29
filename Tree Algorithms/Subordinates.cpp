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

ll n;
vl gr[2 * N], ans(2 * N, 0);

long dfs(long s)
{
    for (auto i : gr[s])
        ans[s] += dfs(i) + 1;
    return ans[s];
}

void solution()
{
    ll tmp;
    cin >> n;
    fo(i, 2, n + 1)
    {
        cin >> tmp;
        gr[tmp].pb(i);
    }
    dfs(1);
    fo(i, 1, n + 1) cout << ans[i] << " ";
}

signed main()
{
    fastIO;
    solution();
    return 0;
}