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
#define plll pair<long long, long long>
#define F first
#define S second
#define fo(i, N) for (long i = 0; i < N; ++i)
#define fos(i, b, N) for (long i = b; i < N; ++i)
#define forr(i, N) for (long i = N; i >= 0; --i)
const double PI = 3.141592653589793238;
const ll oo = 1e18;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;

//  PRIM'S Algorithm Standard

vector<vector<plll>> adj;
ll n, m;
vll key;
vb vis;

void solve()
{
    ll a, b, c, res = 0;
    cin >> n >> m;
    adj.resize(n + 1);
    key.resize(n + 1, oo);
    vis.resize(n + 1, false);

    while (m--)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    priority_queue<plll, vector<plll>, greater<plll>> pq;
    key[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        ll wt = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        if (vis[u])
            continue;
        res += wt;
        vis[u] = true;

        for (auto x : adj[u])
        {
            ll v = x.first;
            ll w1 = x.second;
            if (!vis[v] && key[v] > w1)
            {
                key[v] = w1;
                pq.push({w1, v});
            }
        }
    }

    fo(i, n) if (key[i + 1] == oo)
    {
        cout << "IMPOSSIBLE";
        return;
    }
    cout << res;
}

int main()
{
    fast;
    solve();
    return 0;
}