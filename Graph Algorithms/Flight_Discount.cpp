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

vector<plll> adj;
vector<vll> dist;
long n, m;

void dijkstraSolve(long s)
{
    dist[s][0] = 0;
    dist[s][1] = 0;
    priority_queue<plll, vector<plll>, greater<plll>> pq;
    pq.push({0, s});

    while (!pq.empty)
    {
        ll v = pq.top().first;
        ll dv = pq.top().second;

        for (auto edge : adj[v])
        {
            ll to = edge.first;
            ll len = edge.second;
        }
    }
}

void solve()
{
    long a, b, c;
    cin >> n >> m;
    adj.assign(n + 1, vll());
    for (long i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dist.assign(n + 1, vll(2, -1));

    dijkstraSolve(1);
}

int main()
{
    fast;
    solve();
    return 0;
}