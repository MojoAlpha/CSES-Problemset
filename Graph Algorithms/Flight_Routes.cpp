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
#define plll pair<ll, ll>
#define fo(i, N) for (long i = 0; i < N; ++i)
#define fos(i, b, N) for (long i = b; i < N; ++i)
#define forr(i, N) for (long i = N; i >= 0; --i)
const double PI = 3.141592653589793238;
const ll oo = 1e18;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

using namespace std;

vector<vector<plll>> adj;
ll n, m, k;
vll dist;
priority_queue<ll, vll, greater<ll>> res;

void djikstra(ll s)
{
    dist[s] = 0;
    priority_queue<plll, vector<plll>, greater<plll>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        ll v = pq.top().second;
        ll dv = pq.top().first;
        pq.pop();
        if (dv != dist[v])
            continue;

        for (auto edge : adj[v])
        {
            ll to = edge.first;
            ll len = edge.second;

            if (dist[v] + len <= dist[to])
            {
                dist[to] = dist[v] + len;
                if (to == n)
                    res.push(dist[dist[to]]);
                pq.push({dist[to], to});
            }
        }
    }
}

void solve()
{
    long a, b, c;
    cin >> n >> m >> k;
    adj.resize(n + 1);
    for (long i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dist.resize(n + 1, oo);
    djikstra(1);

    fo(i, n + 1) cout << dist[i] << " ";
    cout << endl;

    while (!res.empty())
    {
        cout << res.top() << " ";
        res.pop();
    }
}

int main()
{
    fast;
    solve();
    return 0;
}