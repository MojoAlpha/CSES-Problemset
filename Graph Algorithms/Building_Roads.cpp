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

/*
This problem can be solved using concept of connected components.
First step towards solving it, is to determine the cluster of cities which need to be connected, which
are just disconnected components in a graph. After determining these fragments, the task is 
to connect them with minimum roads, which can be achieved by placing these fragments in a line 
& joining the adjacent clusters with a road.

EXAMPLE -
    1 1 1----2 2     3------4
     1 1      2-----3 3             ,here same number denotes nodes in same fragment

We can see that, if there are n disconnected fragments, they can be connected by using minimum
(n - 1) roads. Just take a node from a cluster and print it to show which cities are the 
ends of the newly constructed road.

Articles -
> https://cp-algorithms.com/graph/search-for-connected-components.html
> https://www.geeksforgeeks.org/connected-components-in-an-undirected-graph/
*/

vi adj[N], res;
int n, m;

void dfs(int s, vb &vis)
{
    vis[s] = 1;
    for (auto &e : adj[s])
    {
        if (!vis[e])
            dfs(e, vis);
    }
}

signed main()
{
    int ai, bi;
    cin >> n >> m;
    vb vis(n + 1, 0);
    fo(i, 0, m)
    {
        cin >> ai >> bi;
        adj[ai].pb(bi);
        adj[bi].pb(ai);
    }

    fo(i, 1, n + 1)
    {
        if (!vis[i])
        {
            res.pb(i);
            dfs(i, vis);
        }
    }

    cout << res.size() - 1 << endl;
    fo(i, 1, res.size()) cout << res[i] << " " << res[i - 1] << endl;
    return 0;
}